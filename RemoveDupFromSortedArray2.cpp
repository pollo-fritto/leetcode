/*
Given an integer array nums sorted in non-decreasing order, 
emove some duplicates in-place such that each unique element appears at most twice. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.

Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, 
then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. 
You must do this by modifying the input array in-place with O(1) extra memory.

*/

#include <vector>

class Solution {
public: 
/*2 iterators: one to keep track of the last element to keep, the other 
to scan the vector, I just need to check if they are different or if the number of 
copies to keep (2 in this case) is reached */
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }

        if (nums.size() == 1){
            return 1;
        }

        auto current = nums.begin();

        auto uniques = 1, copies = 1;

        for(auto next = nums.begin() + 1; next != nums.end(); next++){
            if(*current == *next  &&  copies >= 2){
                continue;
            }

            if(*current != *next){
                copies = 0;
            }

            uniques++;
            current++;
            *current = *next;
            copies++;            
        }

        return uniques;
    }
};