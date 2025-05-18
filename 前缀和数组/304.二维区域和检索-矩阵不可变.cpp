#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    // preSum[i][j] 记录矩阵 [0, 0, i-1, j-1] 的元素和
    std::vector<std::vector<int>> preSum;

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        // 构造前缀和矩阵
        preSum.resize(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 计算每个矩阵 [0, 0, i, j] 的元素和
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i - 1][j - 1] - preSum[i-1][j-1];
            }
        }
    }
    
    // 计算子矩阵 [x1, y1, x2, y2] 的元素和
    int sumRegion(int x1, int y1, int x2, int y2) {
        // 目标矩阵之和由四个相邻矩阵运算获得
        return preSum[x2+1][y2+1] - preSum[x1][y2+1] - preSum[x2+1][y1] + preSum[x1][y1];
    }
};

int main() {
    // 测试用例
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    
    NumMatrix* obj = new NumMatrix(matrix);
    
    // 测试不同的子矩阵查询
    cout << obj->sumRegion(2, 1, 4, 3) << endl;  // 应该返回 8 (红色矩形)
    cout << obj->sumRegion(1, 1, 2, 2) << endl;  // 应该返回 11 (绿色矩形)
    cout << obj->sumRegion(1, 2, 2, 4) << endl;  // 应该返回 12 (蓝色矩形)
    cout << obj->sumRegion(0, 0, 4, 4) << endl;  // 应该返回 58 (整个矩阵)
    
    delete obj;
    return 0;
}