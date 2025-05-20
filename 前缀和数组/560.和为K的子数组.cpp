#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
private:
        vector<int>presum;
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        presum.resize(n+1,0);
        for(int i = 1; i<=n; i++){
            presum[i] = presum[i-1]+nums[i-1];
        }
        unordered_map<int,int>map;
        int res = 0;
        for(int i =0;i<presum.size();i++){
            int need = presum[i]-k;
            if(map.count(need)){
                res+=map[need];
            }
            map[presum[i]]++;
        }
        return res;        
    }
};

int main() {
    Solution solution;
    
    // 示例测试
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "示例1输出: " << solution.subarraySum(nums1, k1) << endl; // 输出: 2
    
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "示例2输出: " << solution.subarraySum(nums2, k2) << endl; // 输出: 2
    
    vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    cout << "示例3输出: " << solution.subarraySum(nums3, k3) << endl; // 输出: 3
    
    // 额外测试
    vector<int> nums4 = {3, 4, 7, 2, -3, 1, 4, 2};
    int k4 = 7;
    cout << "额外测试1输出: " << solution.subarraySum(nums4, k4) << endl; // 输出: 4
    
    vector<int> nums5 = {1};
    int k5 = 1;
    cout << "额外测试2输出: " << solution.subarraySum(nums5, k5) << endl; // 输出: 1
    
    return 0;
}