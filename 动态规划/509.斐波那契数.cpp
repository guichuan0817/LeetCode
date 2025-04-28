#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int fib(int n) {

        if(n == 0 || n == 1){
            return n;
        }
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
    }
};


int main(){
    Solution solution;

    int n;
    cout <<"Please Enter an Integer: "<<endl;
    cin >> n;

    cout <<"the result is: "<< solution.fib(n) <<endl;
}