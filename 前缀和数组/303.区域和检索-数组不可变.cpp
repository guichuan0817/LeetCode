#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    // 前缀和数组
    std::vector<int> preSum;

    // 输入一个数组，构造前缀和
    public:
    NumArray(std::vector<int>& nums) {
        // preSum[0] = 0，便于计算累加和
        preSum.resize(nums.size() + 1);
        // 计算 nums 的累加和
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }

    // 查询闭区间 [left, right] 的累加和
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

int main() {
    // 测试用例
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    
    // 测试不同的查询
    std::cout << obj->sumRange(0, 2) << std::endl;  // 应该返回 1 (-2 + 0 + 3)
    std::cout << obj->sumRange(2, 5) << std::endl;  // 应该返回 -1 (3 + -5 + 2 + -1)
    std::cout << obj->sumRange(0, 5) << std::endl;  // 应该返回 -3 (所有元素的和)
    
    delete obj;
    return 0;
}