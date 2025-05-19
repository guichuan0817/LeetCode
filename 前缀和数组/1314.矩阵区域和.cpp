#include<iostream>
#include<vector>

using namespace std;

class NumMatrix{
private:
    vector<vector<int>>presum;
public:
    NumMatrix(vector<vector<int>>&matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        presum.resize(m+1, vector<int>(n+1,0));

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                presum[i][j] = presum[i-1][j]+presum[i][j-1]+matrix[i-1][j-1]-presum[i-1][j-1];
            }
        }

    }

    int SumRegion(int x1, int y1, int x2, int y2){
        return presum[x2+1][y2+1] - presum[x2+1][y1]-presum[x1][y2+1]+presum[x1][y1];
    }

};

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        NumMatrix numMatrix(mat);
        vector<vector<int>>res(m,vector<int>(n,0));
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                int x1 = max(0,i-k);
                int y1 = max(0,j-k);
                int x2 = min(i+k,m-1);
                int y2 = min(j+k,n-1);
                res[i][j] = numMatrix.SumRegion(x1,y1,x2,y2);
            }
        }
        return res; 
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k1 = 1;
    vector<vector<int>> result1 = solution.matrixBlockSum(mat1, k1);
    
    cout << "Test case 1 result:" << endl;
    for (const auto& row : result1) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // 测试用例2
    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k2 = 2;
    vector<vector<int>> result2 = solution.matrixBlockSum(mat2, k2);
    
    cout << "\nTest case 2 result:" << endl;
    for (const auto& row : result2) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}