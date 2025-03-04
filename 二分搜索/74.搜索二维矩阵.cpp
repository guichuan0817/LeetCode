#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size(); 
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        // 把二维数组映射到一维
        // 标准的二分搜索框架
        while (left <= right) {
            int mid = left + (right - left)/2;
            if(get(matrix,mid) == target) {
                return true; 
            } 
            else if (get(matrix,mid) < target) {
                left = mid + 1;
            }
            else if (get(matrix,mid)> target) {
                right = mid- 1;
            }
        }   
        return false;
    }
    // 通过一维坐标访问二维数组中的元素 index = i*n + j;
    int get(vector<vector<int>>& matrix,int index) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = index / n;
        int j = index % n;
        return matrix[i][j];
    }
};

int main () {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13 ;
    Solution obj;
    bool res =  obj.searchMatrix(matrix, target);
    if(res == 1) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}