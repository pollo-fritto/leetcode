/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/

#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        //Boyer-Moore voting algorithm
        auto votes = 1;
        auto candidate = nums.begin();

        for(auto iter = nums.begin() + 1; iter < nums.end(); iter++){
            if(*iter == *candidate){
                votes++;
                continue;
            }

            votes--;
            
            if (votes == 0) {
                candidate = iter;
                votes = 1;
            }
        }

        return *candidate;  
    }
};