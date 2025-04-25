#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string target = "123450";
        // 将 2x3 的数组转化成字符串作为 BFS 的起点
        string start ="";
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                start = start + to_string(board[i][j]);
            }
        }      
        // ****** BFS 算法框架开始 ******        
        unordered_set<string>visited;
        queue<string>q;
        // 从起点开始 BFS 搜索
        q.push(start);
        visited.insert(start);
        int step = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; i++){
                string cur = q.front();
                q.pop();
                // 判断是否达到目标局面
                if(cur == target){
                    return step;
                }
                // 将数字 0 和相邻的数字交换位置
                for(string neighbor : GenerateNeighbors(cur)){
                    // 防止走回头路
                    if(!visited.count(neighbor)){
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            step++;
        }
        // ****** BFS 算法框架结束 ******
        return -1;
    }
    //对于 m x n 的二维数组，我们可以写一个函数来生成它的一维索引 neighbor 索引映射
    vector<vector<int>> generateNeighborMapping(int m, int n) {
        vector<vector<int>> neighbor(m * n);
        for (int i = 0; i < m * n; i++) {
            vector<int> neighbors;

            // 如果不是第一列，有左侧邻居
            if (i % n != 0) neighbors.push_back(i - 1);
            // 如果不是最后一列，有右侧邻居
            if (i % n != n - 1) neighbors.push_back(i + 1);
            // 如果不是第一行，有上方邻居
            if (i - n >= 0) neighbors.push_back(i - n);
            // 如果不是最后一行，有下方邻居
            if (i + n < m * n) neighbors.push_back(i + n);

            neighbor[i] = neighbors;
        }
        return neighbor;
    }

    vector<string> GenerateNeighbors(string board){
         // 记录一维字符串的相邻索引
        // vector<vector<int>>mapping = {
        //     {1,3},
        //     {0,2,4},
        //     {1,5},
        //     {0,4},
        //     {3,1,5},
        //     {4,2}
        // };
        vector<vector<int>> neighbor = generateNeighborMapping(2,3);
        vector<string>neighbors;
        int idx = board.find('0');
        for(int adj : neighbor[idx]){
            string new_board = swap(board, idx, adj);
            neighbors.push_back(new_board);

        }
        return neighbors;
    }
    string swap(string s, int i, int j){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return s;
    }
};

// 测试用例
int main() {
    Solution solution;
    
    // 测试用例1: 可以解开的谜板
    vector<vector<int>> board1 = {{1,2,3},{4,0,5}};
    cout << "Test Case 1: " << solution.slidingPuzzle(board1) << endl;  // 应输出1
    
    // 测试用例2: 需要多步解开的谜板
    vector<vector<int>> board2 = {{4,1,2},{5,0,3}};
    cout << "Test Case 2: " << solution.slidingPuzzle(board2) << endl;  // 应输出5
    
    // 测试用例3: 已经是解开的谜板
    vector<vector<int>> board3 = {{1,2,3},{4,5,0}};
    cout << "Test Case 3: " << solution.slidingPuzzle(board3) << endl;  // 应输出0
    
    // 测试用例4: 无法解开的谜板
    vector<vector<int>> board4 = {{1,2,3},{5,4,0}};
    cout << "Test Case 4: " << solution.slidingPuzzle(board4) << endl;  // 应输出-1
    
    return 0;
}