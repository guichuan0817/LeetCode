#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 最多有 1000 个车站
        vector<int> nums(1001, 0);
        // 构造差分解法
        Difference df(nums);

        for (const auto& trip : trips) {
            // 乘客数量
            int val = trip[0];
            // 第 trip[1] 站乘客上车
            int i = trip[1];
            // 第 trip[2] 站乘客已经下车，
            // 即乘客在车上的区间是 [trip[1], trip[2] - 1]
            int j = trip[2] - 1;
            // 进行区间操作
            df.increment(i, j, val);
        }

        vector<int> res = df.result();

        // 客车自始至终都不应该超载
        for (int i = 0; i < res.size(); i++) {
            if (capacity < res[i]) {
                return false;
            }
        }
        return true;
    }

    // 差分数组工具类
    class Difference {
    private:
        // 差分数组
        vector<int> diff;

    public:
        // 输入一个初始数组，区间操作将在这个数组上进行
        Difference(vector<int>& nums) {
            diff.resize(nums.size());
            // 根据初始数组构造差分数组
            diff[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                diff[i] = nums[i] - nums[i - 1];
            }
        }

        // 给闭区间 [i, j] 增加 val（可以是负数）
        void increment(int i, int j, int val) {
            diff[i] += val;
            if (j + 1 < diff.size()) {
                diff[j + 1] -= val;
            }
        }

        // 返回结果数组
        vector<int> result() {
            vector<int> res(diff.size());
            // 根据差分数组构造结果数组
            res[0] = diff[0];
            for (int i = 1; i < diff.size(); i++) {
                res[i] = res[i - 1] + diff[i];
            }
            return res;
        }
    };
};


int main() {
    Solution sol;
    
    // 测试用例1: trips = [[2,1,5],[3,3,7]], capacity = 4
    // 预期输出: false
    vector<vector<int>> trips1 = {{2,1,5}, {3,3,7}};
    int capacity1 = 4;
    cout << "Test Case 1: " << (sol.carPooling(trips1, capacity1) ? "true" : "false") << endl;
    
    // 测试用例2: trips = [[2,1,5],[3,3,7]], capacity = 5
    // 预期输出: true
    vector<vector<int>> trips2 = {{2,1,5}, {3,3,7}};
    int capacity2 = 5;
    cout << "Test Case 2: " << (sol.carPooling(trips2, capacity2) ? "true" : "false") << endl;
    
    // 测试用例3: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
    // 预期输出: true
    vector<vector<int>> trips3 = {{3,2,7}, {3,7,9}, {8,3,9}};
    int capacity3 = 11;
    cout << "Test Case 3: " << (sol.carPooling(trips3, capacity3) ? "true" : "false") << endl;
    
    return 0;
}