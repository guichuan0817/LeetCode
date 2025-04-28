#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    // 记录回溯算法的递归路径
    vector<int>track;
    vector<vector<int>>res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);

        return res;
        
    }
    // 回溯算法核心函数，遍历子集问题的回溯树
    void backtrack(vector<int>& nums, int start){

         // 前序位置，每个节点的值都是一个子集
        res.push_back(track);

        for(int i = start; i<nums.size(); i++){
            // 做选择
            track.push_back(nums[i]);
            // 通过 start 参数控制树枝的遍历，避免产生重复的子集
            backtrack(nums, i+1);
            // 撤销选择
            track.pop_back();
        }

    }
};

// 辅助函数：打印结果
void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[\n";
    for (const auto& subset : subsets) {
        cout << "  [";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) {
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
    vector<int> nums1 = {1, 2, 3};
    cout << "输入: [1, 2, 3]" << endl;
    vector<vector<int>> result1 = solution.subsets(nums1);
    cout << "输出: " << endl;
    printSubsets(result1);
    
    // 测试用例2
    vector<int> nums2 = {0};
    cout << "\n输入: [0]" << endl;
    vector<vector<int>> result2 = solution.subsets(nums2);
    cout << "输出: " << endl;
    printSubsets(result2);
    
    return 0;
}