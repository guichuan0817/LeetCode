#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        int left = 0;
        int right = 0;
        int len = INT16_MIN;
        int windowSum = 0;
        int target = sum-x;
        while(right < nums.size()){
            windowSum += nums[right];
            right++;
            while(windowSum > target && left < right){
                windowSum -= nums[left];
                left++;
            }
            if(windowSum == target){
                len = max(len, right-left);
            }
        }
        return len == INT16_MIN? -1 : nums.size()-len;
    }
};

int main() {
    Solution s;
    // 测试用例1: 示例情况
    {
        vector<int> nums = {1, 1, 4, 2, 3};
        int x = 5;
        int result = s.minOperations(nums, x);
        cout << "测试用例1 - 输入: nums = [1,1,4,2,3], x = 5" << endl;
        cout << "预期结果: 2" << endl;
        cout << "实际结果: " << result << endl << endl;
    }
    
    // 测试用例2: 无法达成的情况
    {
        vector<int> nums = {5, 6, 7, 8, 9};
        int x = 4;
        int result = s.minOperations(nums, x);
        cout << "测试用例2 - 输入: nums = [5,6,7,8,9], x = 4" << endl;
        cout << "预期结果: -1" << endl;
        cout << "实际结果: " << result << endl << endl;
    }
    
    // 测试用例3: 需要多个操作的情况
    {
        vector<int> nums = {3, 2, 20, 1, 1, 3};
        int x = 10;
        int result = s.minOperations(nums, x);
        cout << "测试用例3 - 输入: nums = [3,2,20,1,1,3], x = 10" << endl;
        cout << "预期结果: 5" << endl;
        cout << "实际结果: " << result << endl << endl;
    }
    
    // 测试用例4: 需要移除所有元素
    {
        vector<int> nums = {1, 2, 3};
        int x = 6;
        int result = s.minOperations(nums, x);
        cout << "测试用例4 - 输入: nums = [1,2,3], x = 6" << endl;
        cout << "预期结果: 3" << endl;
        cout << "实际结果: " << result << endl << endl;
    }
    
    // 测试用例5: 空数组
    {
        vector<int> nums = {};
        int x = 1;
        int result = s.minOperations(nums, x);
        cout << "测试用例5 - 输入: nums = [], x = 1" << endl;
        cout << "预期结果: -1" << endl;
        cout << "实际结果: " << result << endl << endl;
    }
    return 0;
}