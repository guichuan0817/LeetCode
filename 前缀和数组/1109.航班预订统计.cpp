#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // nums 初始化为全 0
        vector<int> nums(n, 0);
        // 构造差分解法
        Difference df(nums);

        for (const auto& booking : bookings) {
            // 注意转成数组索引要减一哦
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            // 对区间 nums[i..j] 增加 val
            df.increment(i, j, val);
        }
        // 返回最终的结果数组
        return df.result();
    }

private:
    class Difference {
        // 差分数组
        vector<int> diff;

    public:
        Difference(const vector<int>& nums) {
            diff.resize(nums.size());
            // 构造差分数组
            diff[0] = nums[0];
            for (size_t i = 1; i < nums.size(); ++i) {
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

        vector<int> result() {
            vector<int> res(diff.size());
            // 根据差分数组构造结果数组
            res[0] = diff[0];
            for (size_t i = 1; i < diff.size(); ++i) {
                res[i] = res[i - 1] + diff[i];
            }
            return res;
        }
    };
};

int main() {
    Solution sol;
    
    // 测试用例1: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
    // 预期输出: [10,55,45,25,25]
    vector<vector<int>> bookings1 = {{1,2,10}, {2,3,20}, {2,5,25}};
    int n1 = 5;
    vector<int> res1 = sol.corpFlightBookings(bookings1, n1);
    cout << "Test Case 1: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    // 测试用例2: bookings = [[1,2,10],[2,2,15]], n = 2
    // 预期输出: [10,25]
    vector<vector<int>> bookings2 = {{1,2,10}, {2,2,15}};
    int n2 = 2;
    vector<int> res2 = sol.corpFlightBookings(bookings2, n2);
    cout << "Test Case 2: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    // 测试用例3: bookings = [[1,1,5]], n = 1
    // 预期输出: [5]
    vector<vector<int>> bookings3 = {{1,1,5}};
    int n3 = 1;
    vector<int> res3 = sol.corpFlightBookings(bookings3, n3);
    cout << "Test Case 3: ";
    for (int num : res3) cout << num << " ";
    cout << endl;

    return 0;
}