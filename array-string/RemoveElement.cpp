/*

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, 
you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.

- Return k.

*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }

        /*if(nums.size() == 1){
            return nums[0] != val;
        }*/

        int occurrences = 0;
        auto front = nums.begin(), back = nums.end() - 1; 
        

        while(front != back){
            if(*front != val){
                front++;
                continue;
            }
            
            if(*back == val){
                back--;
                occurrences++;
                continue;
            }

            swap(*front, *back);
            occurrences++;
            back--;
            //front++;
        }

        return nums.size() - occurrences - (*front == val);
    }
};

int main(){
    // int[] nums = [...]; // Input array
    // int val = ...; // Value to remove
    // int[] expectedNums = [...]; // The expected answer with correct length.
                                // It is sorted with no values equaling val.

    // int k = removeElement(nums, val); // Calls your implementation

    // assert k == expectedNums.length;
    // sort(nums, 0, k); // Sort the first k elements of nums
    // for (int i = 0; i < actualLength; i++) {
    //     assert nums[i] == expectedNums[i];
    // }
}