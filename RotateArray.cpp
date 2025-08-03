/*
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.


Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

#include <vector>
#include <iostream>
/*
The number of useful rotation is k % nums.size()
Create an empty vector tmp_vec of the same size of nums,
copy elements of nums inside tmp_vec shifted by k % nums.size()
positions.
Swap the 2 vectors. 
*/

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (k == 0){
            return;
        }

        int effective_rot = k % nums.size(); 
        if (effective_rot == 0){
            return;
        }

        std::vector<int> tmp_vec;
        tmp_vec.resize(nums.size());

        int i;
        for (i = 0; i < nums.size() - effective_rot; i++){
            tmp_vec[i + effective_rot] = nums[i];    
        }

        for (int j = i; j < nums.size(); j++){
            tmp_vec[j - i] = nums[j];
        }
        
        tmp_vec.swap(nums);
    }
};

void printVector(std::vector<int>& v) {
    for (auto x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main(){
    Solution sol;

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    printVector(vec);

    sol.rotate(vec, 14);

    printVector(vec);

    sol.rotate(vec, 23);

    printVector(vec);

    return 0;

}