#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            // 以 s[i] 为中心的最长回文子串
            string s1 = Palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = Palindrome(s, i, i+1);

            res = res.size() > s1.size()? res : s1;
            res = res.size() > s2.size()? res : s2;
        }
        return res;
        
    }

    string Palindrome(string s, int l, int r) {
        // 防止索引越界
        while(l >= 0 && r < s.size() && s[l]==s[r]){
            // 向两边展开
            l--;
            r++;
        }
        // 此时 [l+1, r-1] 就是最长回文串
        return s.substr(l+1, r-l-1);

    }
};

int main() {
    Solution solution;
    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Longest palindromic substring: " << solution.longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Input: " << s2 << endl;
    cout << "Longest palindromic substring: " << solution.longestPalindrome(s2) << endl;

    return 0;
}