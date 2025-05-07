#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1){
            return 0; // 因为所有数都是正整数，乘积至少是1，所以k<=1时无解
        }
        int left = 0;
        int right = 0;
        // 滑动窗口，初始化为乘法单位元
        int windowMul = 1;
        // 记录符合条件的子数组个数
        int count = 0;
        while(right < nums.size()){
            // 扩大窗口，并更新窗口数据
            windowMul *= nums[right];
            right++;

            while(windowMul >=k && left < right){
                // 缩小窗口，并更新窗口数据
                windowMul /= nums[left];
                left++;
            }
            // 现在必然是一个合法的窗口，但注意思考这个窗口中的子数组个数怎么计算：
            // 比方说 left = 1, right = 4 划定了 [1, 2, 3] 这个窗口（right 是开区间）
            // 但不止 [left..right] 是合法的子数组，[left+1..right], [left+2..right] 等都是合法子数组
            // 所以我们需要把 [3], [2,3], [1,2,3] 这 right - left 个子数组都加上
            count += right-left;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // 测试用例1: 示例输入
    {
        vector<int> nums = {10, 5, 2, 6};
        int k = 100;
        int expected = 8;
        int result = sol.numSubarrayProductLessThanK(nums, k);
        cout << "Test case 1: ";
        if (result == expected) {
            cout << "Passed (Expected: " << expected << ", Got: " << result << ")" << endl;
        } else {
            cout << "Failed (Expected: " << expected << ", Got: " << result << ")" << endl;
        }
    }

    // 测试用例2: k=0，无解
    {
        vector<int> nums = {1, 2, 3};
        int k = 0;
        int expected = 0;
        int result = sol.numSubarrayProductLessThanK(nums, k);
        cout << "Test case 2: ";
        if (result == expected) {
            cout << "Passed (Expected: " << expected << ", Got: " << result << ")" << endl;
        } else {
            cout << "Failed (Expected: " << expected << ", Got: " << result << ")" << endl;
        }
    }

    // 测试用例3: 所有子数组都满足条件
    {
        vector<int> nums = {1, 1, 1};
        int k = 10;
        int expected = 6; // 3 + 2 + 1 = 6
        int result = sol.numSubarrayProductLessThanK(nums, k);
        cout << "Test case 3: ";
        if (result == expected) {
            cout << "Passed (Expected: " << expected << ", Got: " << result << ")" << endl;
        } else {
            cout << "Failed (Expected: " << expected << ", Got: " << result << ")" << endl;
        }
    }

    // 测试用例4: 空数组
    {
        vector<int> nums = {};
        int k = 100;
        int expected = 0;
        int result = sol.numSubarrayProductLessThanK(nums, k);
        cout << "Test case 4: ";
        if (result == expected) {
            cout << "Passed (Expected: " << expected << ", Got: " << result << ")" << endl;
        } else {
            cout << "Failed (Expected: " << expected << ", Got: " << result << ")" << endl;
        }
    }

    // 测试用例5: 大数测试
    {
        vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int k = 1000;
        int expected = 30;
        int result = sol.numSubarrayProductLessThanK(nums, k);
        cout << "Test case 5: ";
        if (result == expected) {
            cout << "Passed (Expected: " << expected << ", Got: " << result << ")" << endl;
        } else {
            cout << "Failed (Expected: " << expected << ", Got: " << result << ")" << endl;
        }
    }

    return 0;
}