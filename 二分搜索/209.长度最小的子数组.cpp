#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int start = 0;
        int end = 0;
        int sum = 0; //维护变量 sum 存储子数组中的元素和（即从 nums[start] 到 nums[end] 的元素和）
        int ans = INT32_MAX;
        while(end < n) {
            sum += nums[end];
            if(sum >= target) {
                ans = min(ans, end-start+1);
                sum -= nums[start]; 
                start++;
            }
            end++;
        }
        return ans == INT32_MAX? 0 : ans;
    }
};

int main() {
    int target = 7;
    vector<int>nums = {2, 3, 1, 2, 4, 3};
    Solution res;
    cout << res.minSubArrayLen(target, nums) <<endl;
}