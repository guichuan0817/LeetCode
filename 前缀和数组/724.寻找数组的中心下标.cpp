#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int>presum;
        presum.resize(n+1,0);
        for(int i = 1; i<=n; i++){
            presum[i] = presum[i-1]+nums[i-1];
        }
        // 根据前缀和判断左半边数组和右半边数组的元素和是否相同
        for(int i=1; i< presum.size(); i++){
            // 计算 nums[i-1] 左侧和右侧的元素和
            int leftsum = presum[i-1]-presum[0];
            int rightsum = presum[n]-presum[i];
            if(leftsum == rightsum){
                // 相对 nums 数组，preSum 数组有一位索引偏移
                return i-1;
            }
        }
        return -1;     
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Test case 1: " << solution.pivotIndex(nums1) << endl;  // 输出应为3
    
    // 测试用例2
    vector<int> nums2 = {1, 2, 3};
    cout << "Test case 2: " << solution.pivotIndex(nums2) << endl;  // 输出应为-1
    
    // 测试用例3
    vector<int> nums3 = {2, 1, -1};
    cout << "Test case 3: " << solution.pivotIndex(nums3) << endl;  // 输出应为0
    
    // 测试用例4
    vector<int> nums4 = {0, 0, 0, 0, 1};
    cout << "Test case 4: " << solution.pivotIndex(nums4) << endl;  // 输出应为4
    
    return 0;
}