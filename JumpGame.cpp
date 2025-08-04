/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
		if(nums[0] == 0){
			return false;
		}

		if (std::find(nums.begin(), nums.end(), 0) == nums.end()){
			return true;
		}

		auto max_jump = nums.begin(), zeroes = nums.begin();
		int needed_jump = 0;

		for(auto max_jump = nums.begin(); max_jump < nums.end(); max_jump++){
			if(*max_jump == 0){
				max_jump--;
				
				while(*zeroes == 0  &&  max_jump != nums.begin()){
					needed_jump++;
					if (needed_jump < *max_jump){
						zeroes++;
					}
				}
			}
		}

		// auto cursor = nums.begin();

		// while(cursor != (nums.end() - 1)  ||  *cursor != 0){
		// 	cursor += *cursor;
		// }

		// if (cursor == (nums.end() - 1)){
		// 	return false;
		// }

		// return true;
    }
};