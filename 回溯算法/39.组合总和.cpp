#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    // 记录 track 中的路径和
    vector<vector<int>>res;
    // 记录回溯的路径
    vector<int>track;
    int tracksum = 0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        track.clear();
        res.clear();
        backtrack(candidates,0,target);
        return res;
        
    }

    // 回溯算法主函数
    void backtrack(vector<int>&nums, int start, int target){
        // base case，找到目标和，记录结果
        if(tracksum == target){
            res.push_back(track);
        }
        // base case，超过目标和，停止向下遍历
        if(tracksum > target){
            return;
        }

        // 回溯算法标准框架
        for(int i = start; i < nums.size(); i++){
            // 选择 nums[i]
            track.push_back(nums[i]);
            tracksum += nums[i];
            // 递归遍历下一层回溯树
            // 同一元素可重复使用，注意参数
            backtrack(nums, i, target);
            // 撤销选择 nums[i]
            track.pop_back();
            tracksum -= nums[i];
        }
    }
};

void printResult(const vector<vector<int>>& result) {
    cout << "[" << endl;
    for (const auto& combination : result) {
        cout << "  [";
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    auto result1 = solution.combinationSum(candidates1, target1);
    cout << "Test case 1:" << endl;
    printResult(result1);
    
    // 测试用例2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    auto result2 = solution.combinationSum(candidates2, target2);
    cout << "Test case 2:" << endl;
    printResult(result2);
    
    // 测试用例3 (无解情况)
    vector<int> candidates3 = {2};
    int target3 = 1;
    auto result3 = solution.combinationSum(candidates3, target3);
    cout << "Test case 3:" << endl;
    printResult(result3);
    
    return 0;
}