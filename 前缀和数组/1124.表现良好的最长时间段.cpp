#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
private:
    vector<int>presum;
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        presum.resize(n+1,0);
        for(int i = 1; i<=n;i++){
            presum[i] = presum[i-1]+(hours[i-1]>8? 1 : -1);
        }
        unordered_map<int,int>valToindex;
        int res = 0;
        for(int i = 0; i<presum.size(); i++){
            if(!valToindex.count(presum[i])){
                valToindex[presum[i]] = i;
            }

            if(presum[i]>0){
                res = max(res,i);
            }
            else{
                if(valToindex.count(presum[i]-1)){
                    int j = valToindex[presum[i]-1];
                    res = max(res, i-j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // 测试用例1: [9,9,6,0,6,6,9] → 输出3（[9,9,6]）
    vector<int> hours1 = {9,9,6,0,6,6,9};
    cout << sol.longestWPI(hours1) << endl; // 预期输出: 3

    // 测试用例2: [6,6,6] → 输出0（没有满足条件的区间）
    vector<int> hours2 = {6,6,6};
    cout << sol.longestWPI(hours2) << endl; // 预期输出: 0

    // 测试用例3: [1,1,-1,-1,1,1] → 输出6（整个数组和为2 > 0）
    vector<int> hours3 = {1,1,-1,-1,1,1};
    cout << sol.longestWPI(hours3) << endl; // 预期输出: 6

    return 0;
}