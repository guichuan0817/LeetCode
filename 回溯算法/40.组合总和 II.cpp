#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


class Solution {
private:
    vector<vector<int>>res;
    // 记录回溯的路径
    vector<int>track;
    // 记录 track 中的元素之和
    int tracksum = 0;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        track.clear();
        // 先排序，让相同的元素靠在一起
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
        
    }

    // 回溯算法主函数
    void backtrack(vector<int>& nums, int start, int target){

        //int sum = accumulate(track.begin(), track.end(), 0);
        // base case，达到目标和，找到符合条件的组合
        if(tracksum == target){
            res.push_back(track);
        }
        // base case，超过目标和，直接结束
        if(tracksum > target){
            return;
        }
        // 回溯算法标准框架
        for(int i = start; i < nums.size(); i++){
            // 剪枝逻辑，值相同的树枝，只遍历第一条
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            tracksum += nums[i];
            // 递归遍历下一层回溯树
            backtrack(nums, i+1, target);
            // 撤销选择
            track.pop_back();
            tracksum -= nums[i];

        }
    }
};

// 辅助函数：打印结果
void printCombinations(const vector<vector<int>>& combinations) {
    cout << "[\n";
    for (const auto& comb : combinations) {
        cout << "  [";
        for (size_t i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size() - 1) {
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
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    cout << "测试用例1:\n输入: candidates = [10,1,2,7,6,1,5], target = 8" << endl;
    vector<vector<int>> result1 = solution.combinationSum2(candidates1, target1);
    cout << "输出: " << endl;
    printCombinations(result1);
    
    // 测试用例2
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    cout << "\n测试用例2:\n输入: candidates = [2,5,2,1,2], target = 5" << endl;
    vector<vector<int>> result2 = solution.combinationSum2(candidates2, target2);
    cout << "输出: " << endl;
    printCombinations(result2);
    
    // 测试用例3
    vector<int> candidates3 = {1, 1, 1, 1, 1};
    int target3 = 3;
    cout << "\n测试用例3:\n输入: candidates = [1,1,1,1,1], target = 3" << endl;
    vector<vector<int>> result3 = solution.combinationSum2(candidates3, target3);
    cout << "输出: " << endl;
    printCombinations(result3);
    
    return 0;
}