/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, 
to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain 
the unique elements in the order they were present in nums initially. 
The remaining elements of nums are not important as well as the size of nums.
    
- Return k.

*/

#include <vector>

/*The list is sorted so duplicates will be contiguous.
I used 2 iterators to scan the list: current keeps track of the element 
we are checking duplicates for, next checks every element of the array. 
If the values of the iterators are equivalent do nothing, 
if they are different current advances of one position and saves the value of next.
In this way the task is performed in one scan,  O(n)*/
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }

        if (nums.size() == 1){
            return 1;
        }

        auto current = nums.begin();
        //auto next = nums.begin() + 1;

        auto uniques = 1;

        for(auto next = nums.begin() + 1; next != nums.end(); next++){
            if(*current == *next){
                continue;
            }

            uniques++;
            current++;
            *current = *next;
        }

        return uniques;
    }
};