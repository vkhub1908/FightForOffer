# 牛客网刷题

## NC50

需要使用dummy指针加单个插入的方法，生成的链表连续不会断开，比较好处理

```c++
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
      if (!head || k < 2 || !head->next) return head;
      ListNode *pCur = head;
      ListNode *pDummy = new ListNode(0);
      pDummy->next = pCur;
      ListNode *pPrev = pDummy, *pNext = nullptr;
      int node_num = 0;
      while (head) {
        ++node_num;
        head = head->next;
      }
      for (int i = 0; i < node_num / k; ++i) {
        for (int j = 1; j < k; ++j) {
          pNext = pCur->next;
          pCur->next = pCur->next->next;
          pNext->next = pPrev->next;
          pPrev->next = pNext;
        }
        pPrev = pCur;
        pCur = pCur->next;
      }
      head = pDummy->next;
      delete pDummy;
      return head;
    }
};
```

# ![nc50](../img/nc50.jpeg)
