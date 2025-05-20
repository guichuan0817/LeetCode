#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
private:
        vector<int>presum;
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        presum.resize(n+1,0);
        for(int i = 1; i<=n; i++){
            presum[i] = presum[i-1]+nums[i-1];
        }
        unordered_map<int,int>valToindex;
        for(int i = 0; i<presum.size(); i++){
            int val = presum[i]%k;
            if(!valToindex.count(val)){
                valToindex[val] = i;
            }
        }
        for(int i = 0; i < presum.size(); i++){
            int need = presum[i]%k;
            if(valToindex.count(need)){
                if(i-valToindex[need]>=2){
                    return true;
                }
            }
        }
        return false;        
    }
};

int main() {
    Solution solution;
    
    // 示例测试
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    cout << "示例1输出: " << (solution.checkSubarraySum(nums1, k1) ? "true" : "false") << endl; // 输出: true ([2,4])
    
    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    cout << "示例2输出: " << (solution.checkSubarraySum(nums2, k2) ? "true" : "false") << endl; // 输出: true ([23,2,6,4,7])
    
    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;
    cout << "示例3输出: " << (solution.checkSubarraySum(nums3, k3) ? "true" : "false") << endl; // 输出: false
    
    // 额外测试
    vector<int> nums4 = {5, 0, 0, 0};
    int k4 = 3;
    cout << "额外测试1输出: " << (solution.checkSubarraySum(nums4, k4) ? "true" : "false") << endl; // 输出: true ([0,0])
    
    vector<int> nums5 = {1, 2, 3};
    int k5 = 5;
    cout << "额外测试2输出: " << (solution.checkSubarraySum(nums5, k5) ? "true" : "false") << endl; // 输出: true ([2,3])
    
    return 0;
}