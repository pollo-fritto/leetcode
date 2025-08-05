/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.


*/

#include <vector>
// #include <algorithm>

/* 
A waaaay cleaner and better solution than mine
*/

bool canJump(std::vector<int>& nums) {
	//it shows at max what index can I reach.
	//initially I can only reach index 0, hence reach = 0
	int reach = 0; 

	for(int idx = 0; idx < nums.size(); idx++) {
		//at every index I'll check if my reach was atleast able to 
		//reach that particular index.
		
		//reach >= idx -> great, carry on. Otherwise, 
		if(reach < idx) return false;
		
		//now as you can reach this index, it's time to update your reach
		//as at every index, you're getting a new jump length.
		reach = std::max(reach, idx + nums[idx]);
	}
	
	//this means that you reached till the end of the array, wohooo!! 
	return true;
	
}

/*
Only zeroes can block us from returning true.
We traverse the list once. 
If the current element is a zero, we loop:
- if the preceding element can jump over, we
look at the element after the zero
- else we check the element even before
If we reach the end we return true.
If we reach the beginning while looking for a
candidate able to jump every zero, we return false
*/
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
		if(nums.size() == 1){
			return true;
		}

		if(nums[0] == 0){
			return false;
		}

		int needed_jump;

		for(auto max_jump = nums.begin() + 1; max_jump < nums.end(); max_jump++){
			if(*max_jump >= nums.end() - max_jump - 1){
				return true;
			}
			
			if(*max_jump != 0){
				continue;
			}

			auto zeroes = max_jump;
			max_jump--;
			needed_jump = 0;
			do{
				needed_jump++;
				if (needed_jump < *max_jump){
					if (zeroes == nums.end() - 2)
						return true;
					zeroes++;
					continue;
				}

				if(max_jump == nums.begin()){
					return false;
				}
				max_jump--;

			}while(*zeroes == 0);

			max_jump = zeroes;
		}

		return true;

    }
};