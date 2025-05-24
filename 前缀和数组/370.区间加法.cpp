#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // nums 初始化为全 0
        vector<int>nums(length,0);
        Difference df(nums);
        for(auto update : updates){
            int i = update[0];
            int j = update[1];
            int val = update[2];
            df.increament(i,j,val);
        }
        return df.result();

    }

    class Difference{
            vector<int>diff;

            public:
                Difference(vector<int>&nums){
                    int n = nums.size();
                    diff.resize(nums.size(),0);
                    for(int i=1; i<n; i++){
                        nums[i] = nums[i-1] + diff[i];
                    }

                }

                void increament(int i, int j, int val){
                    diff[i]+=val;
                    if(j+1<diff.size()){
                        diff[j+1]-=val;
                    }

                }

                vector<int> result(){
                    vector<int>res(diff.size(),0);
                    res[0] = diff[0];
                    for(int i =1; i<diff.size(); i++){
                        res[i] = res[i-1]+ diff[i]; 
                    }
                    return res;
                }
            };
};



int main() {
    Solution sol;
    
    // 测试用例1: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    // 预期输出: [-2,0,3,5,3]
    int length1 = 5;
    vector<vector<int>> updates1 = {{1,3,2}, {2,4,3}, {0,2,-2}};
    vector<int> res1 = sol.getModifiedArray(length1, updates1);
    cout << "Test Case 1: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    // 测试用例2: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
    // 预期输出: [0,-4,2,2,2,6,4,-4,-4,-4]
    int length2 = 10;
    vector<vector<int>> updates2 = {{2,4,6}, {5,6,8}, {1,9,-4}};
    vector<int> res2 = sol.getModifiedArray(length2, updates2);
    cout << "Test Case 2: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    // 测试用例3: length = 3, updates = [[0,2,5],[1,1,-3]]
    // 预期输出: [5,2,5]
    int length3 = 3;
    vector<vector<int>> updates3 = {{0,2,5}, {1,1,-3}};
    vector<int> res3 = sol.getModifiedArray(length3, updates3);
    cout << "Test Case 3: ";
    for (int num : res3) cout << num << " ";
    cout << endl;

    return 0;
}