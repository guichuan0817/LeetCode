#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    vector<int>presum;
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // 计算 nums 的前缀和
        presum.resize(n+1, 0);
        for(int i = 1; i<=n; i++){
            presum[i] = presum[i-1] + (nums[i-1] == 0? -1 :1);
        }
        // 前缀和到索引的映射，方便快速查找所需的前缀和
        unordered_map<int,int>valToindex;
        int res = 0;
        for(int i = 0; i< presum.size(); i++){
             // 这个前缀和已经出现过了，则找到一个和为 0 的子数组
            if(valToindex.count(presum[i])){
                res = max(res, i - valToindex[presum[i]]);
            } 
             // 如果这个前缀和还没有对应的索引，说明这个前缀和第一次出现，记录下来
            else
            {
                valToindex[presum[i]] = i;
            }
            // 因为题目想找长度最大的子数组，所以前缀和索引应尽可能小
        }
        return res;  
    }
};

int main() {
    Solution solution;
    
    // 示例测试
    vector<int> nums1 = {0, 1};
    cout << "示例1输出: " << solution.findMaxLength(nums1) << endl; // 输出: 2

    vector<int> nums2 = {0, 1, 0};
    cout << "示例2输出: " << solution.findMaxLength(nums2) << endl; // 输出: 2

    vector<int> nums3 = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    cout << "示例3输出: " << solution.findMaxLength(nums3) << endl; // 输出: 6

    // 额外测试
    vector<int> nums4 = {0, 0, 1, 0, 0, 0, 1, 1};
    cout << "额外测试输出: " << solution.findMaxLength(nums4) << endl; // 输出: 6 ([1,0,0,0,1,1])

    return 0;
}