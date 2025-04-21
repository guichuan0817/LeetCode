#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>window;
        int left = 0;
        int right = 0;
        // 记录结果
        int res = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            window[c]++;
            // 判断左侧窗口是否要收缩
            while(window[c] > 1){
                char d= s[left];
                left++;
                // 进行窗口内数据的一系列更新
                window[d]--;
            }
             // 在这里更新答案
            res = max(res, right-left);
        }
        return res;   
    }
};

int main() {
    Solution solution;
    string input;
    
    cout << "请输入一个字符串: ";
    getline(cin, input);
    
    int result = solution.lengthOfLongestSubstring(input);
    
    cout << "不含重复字符的最长子串长度为: " << result << endl;
    
    return 0;
}