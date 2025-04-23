#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>>res;

public:
    // 主函数，输入一组不重复的数字，返回它们的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        // 记录「路径」
        vector<int>track;
        // 「路径」中的元素会被标记为true，避免重复使用
        vector<bool>used(nums.size(),false);

        backtrack(nums, track, used);

        return res;   
    }

    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(vector<int>&nums, vector<int>&track, vector<bool>&used){
        // 触发结束条件
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for(int i=0; i < nums.size(); i++){
            // 排除不合法的选择
            if(used[i]){
                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 进入下一层决策树
            backtrack(nums, track, used);
            // 取消选择
            track.pop_back();
            used[i] = false;

        }

    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // 示例输入
    vector<vector<int>> permutations = solution.permute(nums);

    // 输出所有排列
    cout << "All possible permutations:" << endl;
    for (const auto& perm : permutations) {
        cout << "[";
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i != perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}