#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        // 统计窗口中每个字符的出现次数
        unordered_map<char,int> windowCharCount;
        // 记录窗口中字符的最多重复次数
        // 记录这个值的意义在于，最划算的替换方法肯定是把其他字符替换成出现次数最多的那个字符
        int windowMaxCount = 0;
        // 记录结果长度
        int res = 0;

        // 开始滑动窗口模板
        while (right < s.length()) {
            // 扩大窗口
            char c = s[right];
            windowCharCount[c]++;
            windowMaxCount = max(windowMaxCount, windowCharCount[c]);
            right++;

            // 这个 while 换成 if 也可以
            while (right - left - windowMaxCount > k) {
                // 杂牌字符数量 right - left - windowMaxCount 多于 k
                // 此时，k 次替换已经无法把窗口内的字符都替换成相同字符了
                // 必须缩小窗口
                char d = s[left];
                windowCharCount[d]--;
                left++;
            }
            // 经过收缩后，此时一定是一个合法的窗口
            res = max(res, right - left);
        }
        return res;
    }
};


int main() {
    Solution solution;
    
    // 测试用例1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test case 1: " << solution.characterReplacement(s1, k1) << endl;  // 预期输出: 4
    
    // 测试用例2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test case 2: " << solution.characterReplacement(s2, k2) << endl;  // 预期输出: 4
    
    // 测试用例3 - 全相同字符
    string s3 = "AAAAA";
    int k3 = 2;
    cout << "Test case 3: " << solution.characterReplacement(s3, k3) << endl;  // 预期输出: 5
    
    // 测试用例4 - 需要替换多个字符
    string s4 = "ABCDEFG";
    int k4 = 3;
    cout << "Test case 4: " << solution.characterReplacement(s4, k4) << endl;  // 预期输出: 4
    
    // 测试用例5 - 空字符串
    string s5 = "";
    int k5 = 2;
    cout << "Test case 5: " << solution.characterReplacement(s5, k5) << endl;  // 预期输出: 0
    
    return 0;
}