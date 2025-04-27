#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
private:
    vector<vector<int>>res;
    vector<int>track;
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();    // 清空之前的结果
        track.clear();  // 清空当前的追踪路径

        backtrack(n, 1, k);
        return res;
    }

    // 回溯算法核心函数，遍历子集问题的回溯树
    void backtrack(int n, int start, int k){
        // 前序位置，每个节点的值都是一个子集
        if(k == track.size()){
            res.push_back(track);
        }

        for(int i=start; i <= n; i++){
            // 做选择
            track.push_back(i);
            // 通过 start 参数控制树枝的遍历，避免产生重复的子集
            backtrack(n, i+1, k);
            // 撤销选择
            track.pop_back();
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
    int n1 = 4, k1 = 2;
    cout << "输入: n = " << n1 << ", k = " << k1 << endl;
    vector<vector<int>> result1 = solution.combine(n1, k1);
    cout << "输出: " << endl;
    printCombinations(result1);
    
    // 测试用例2
    int n2 = 5, k2 = 3;
    cout << "\n输入: n = " << n2 << ", k = " << k2 << endl;
    vector<vector<int>> result2 = solution.combine(n2, k2);
    cout << "输出: " << endl;
    printCombinations(result2);
    
    // 测试用例3
    int n3 = 1, k3 = 1;
    cout << "\n输入: n = " << n3 << ", k = " << k3 << endl;
    vector<vector<int>> result3 = solution.combine(n3, k3);
    cout << "输出: " << endl;
    printCombinations(result3);
    
    return 0;
}