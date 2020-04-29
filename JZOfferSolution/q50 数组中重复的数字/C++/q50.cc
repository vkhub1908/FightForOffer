class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length < 1) return false;
        unordered_set<int> mySet;
        auto iter = mySet.end();
        for (int i = 0; i < length; ++i) {
            iter = mySet.find(numbers[i]);
            if (iter == mySet.end()) {
                mySet.insert(numbers[i]);
            } else {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
