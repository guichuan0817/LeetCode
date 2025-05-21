#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
        vector<int>presum;
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        presum.resize(n+1,0);
        for(int i = 1; i <= n; i++){
            presum[i] = presum[i-1] + nums[i-1];
        }
        unordered_map<int, int>map;
        int res = 0;
        for(int i = 0; i < presum.size(); i++){
            int val = presum[i]%k;
            //在计算子数组和是否能被 K 整除时，我们需要统计 相同余数的前缀和。
            //如果不对负余数进行调整，-2 和 1 会被视为不同的余数，导致统计错误。调整后：
            //-2 和 1 都会被视为 1，从而正确计数。
            //val + K 的作用：将负余数调整到 [0, K-1] 范围内，确保余数的正确性。
            //关键点：在涉及模运算的问题中（尤其是哈希表统计余数时），必须统一余数为非负数，否则会导致错误。
            if(val < 0){
                val += k;
            }
            if(map.count(val)){
                res += map[val];
            }
            map[val]++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // 测试用例1: [4,5,0,-2,-3,1], K=5 → 7
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Test Case 1: " << sol.subarraysDivByK(nums1, k1) << endl; // 输出 7

    // 测试用例2: [5], K=9 → 0
    vector<int> nums2 = {5};
    int k2 = 9;
    cout << "Test Case 2: " << sol.subarraysDivByK(nums2, k2) << endl; // 输出 0

    // 测试用例3: [1, -1, 1, -1], K=2 → 4
    vector<int> nums3 = {1, -1, 1, -1};
    int k3 = 2;
    cout << "Test Case 3: " << sol.subarraysDivByK(nums3, k3) << endl; // 输出 4

    return 0;
}