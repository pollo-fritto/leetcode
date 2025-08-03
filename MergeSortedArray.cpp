/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

*/

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int copyIndex, nums2Index, totalElems, nums1Copy[200];
        //std::vector<int> nums1Copy(m);
        nums2Index = 0;
        copyIndex = 0;
        totalElems = n + m;
        
        //copy the first m elems of nums1 in nums1Copy
        std::copy(nums1.begin(), nums1.begin() + m, nums1Copy);
        //std::copy(nums1.begin(), nums1.begin() + m, nums1Copy.begin());

        for(int nums1Index = 0; nums1Index < totalElems; nums1Index++){
            if(nums2Index >= n){ //nums2 is over
                std::copy(&nums1Copy[copyIndex], &nums1Copy[m], nums1.begin() + nums1Index);
                //std::copy(nums1Copy.begin() + copyIndex, nums1Copy.end(), nums1.begin() + nums1Index);
                break;
            }
            
            if(copyIndex >= m){//nums1Copy is over
                std::copy(nums2.begin() + nums2Index, nums2.end(), nums1.begin() + nums1Index);
                break;
            }
            
            if(nums1Copy[copyIndex] < nums2[nums2Index]){
                nums1[nums1Index] = nums1Copy[copyIndex];
                copyIndex++;
                continue;
            }
            
            nums1[nums1Index] = nums2[nums2Index];
            nums2Index++;
        }


    }
};