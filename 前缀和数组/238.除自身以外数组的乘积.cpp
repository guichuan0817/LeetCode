#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // 从左到右的前缀积，prefix[i] 是 nums[0..i] 的元素积
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        // 从右到左的前缀积，suffix[i] 是 nums[i..n-1] 的元素积
        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        // 结果数组
        vector<int> res(n);
        res[0] = suffix[1];
        res[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            // 除了 nums[i] 自己的元素积就是 nums[i] 左侧和右侧所有元素之积
            res[i] = prefix[i - 1] * suffix[i + 1];
        }
        return res;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;  // 输出应为 24 12 8 6
    
    // 测试用例2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;  // 输出应为 0 0 9 0 0
    
    // 测试用例3
    vector<int> nums3 = {2, 3, 5, 7};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test case 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;  // 输出应为 105 70 42 30
    
    return 0;
}