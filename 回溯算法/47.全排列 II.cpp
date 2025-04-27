#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
private:
    vector<vector<int>>res;
    vector<int>track;
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        track.clear();
        
        vector<bool>used(nums.size(),false);
        // 先排序，让相同的元素靠在一起
        sort(nums.begin(), nums.end());
        backtrack(nums,track, used);
        return res;
    }

    void backtrack(vector<int>&nums, vector<int>&track, vector<bool>&used){
        if(track.size()==nums.size()){
            res.push_back(track);
        }

        for(int i=0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }
            // 新添加的剪枝逻辑，固定相同的元素在排列中的相对位置

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                // 如果前面的相邻相等元素没有用过，则跳过
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }

    }
};


// 辅助函数：打印结果
void printPermutations(const vector<vector<int>>& permutations) {
    cout << "[\n";
    for (const auto& perm : permutations) {
        cout << "  [";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i != perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

// 测试用例
int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {1, 1, 2};
    cout << "测试用例1:\n输入: nums = [1,1,2]" << endl;
    vector<vector<int>> result1 = solution.permuteUnique(nums1);
    cout << "输出: " << endl;
    printPermutations(result1);
    
    // 测试用例2
    vector<int> nums2 = {2, 2, 1, 1};
    cout << "\n测试用例2:\n输入: nums = [2,2,1,1]" << endl;
    vector<vector<int>> result2 = solution.permuteUnique(nums2);
    cout << "输出: " << endl;
    printPermutations(result2);
    
    // 测试用例3
    vector<int> nums3 = {1, 2, 3};
    cout << "\n测试用例3:\n输入: nums = [1,2,3]" << endl;
    vector<vector<int>> result3 = solution.permuteUnique(nums3);
    cout << "输出: " << endl;
    printPermutations(result3);
    
    return 0;
}