#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int windowOnecount = 0;
        int len = 0;

        while(right < nums.size()){
            if(nums[right]==1){
                windowOnecount++;
            }
            right++;
            while(right-left - windowOnecount > k){
                if(nums[left]==1){
                    windowOnecount--;
                }
                left++;
            }
            len = max(len, right-left);
        }
        return len;    
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << "Test case 1: " << solution.longestOnes(nums1, k1) << endl;  // 预期输出: 6
    
    // 测试用例2
    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k2 = 3;
    cout << "Test case 2: " << solution.longestOnes(nums2, k2) << endl;  // 预期输出: 10
    
    // 测试用例3 - 全1数组
    vector<int> nums3 = {1,1,1,1,1};
    int k3 = 2;
    cout << "Test case 3: " << solution.longestOnes(nums3, k3) << endl;  // 预期输出: 5
    
    // 测试用例4 - 全0数组
    vector<int> nums4 = {0,0,0,0};
    int k4 = 2;
    cout << "Test case 4: " << solution.longestOnes(nums4, k4) << endl;  // 预期输出: 2
    
    return 0;
}