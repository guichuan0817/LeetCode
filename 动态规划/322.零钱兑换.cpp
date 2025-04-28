#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //数组大小为 amount + 1，初始值也为 amount + 1
        //为啥 dp 数组中的值都初始化为 amount + 1 呢，
        //因为凑成 amount 金额的硬币数最多只可能等于 amount（全用 1 元面值的硬币），
        //所以初始化为 amount + 1 就相当于初始化为正无穷，便于后续取最小值。
        //为啥不直接初始化为 int 型的最大值 Integer.MAX_VALUE 呢？因为后面有 dp[i - coin] + 1，这就会导致整型溢出。
        vector<int>dp(amount+1, amount+1);
        // base case
        // 外层 for 循环在遍历所有状态的所有取值
        dp[0] = 0;
        for(int i =0; i < dp.size(); i++){
            // 内层 for 循环在求所有选择的最小值
            for(auto coin : coins){
                // 子问题无解，跳过
                if(i-coin < 0){
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == (amount+1)? -1:dp[amount];
        
    }
};

int main(){
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl; // 输出：3
}