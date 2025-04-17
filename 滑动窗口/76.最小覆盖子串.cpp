#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(char c : t){
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT32_MAX;

        while(right < s.size()){
            char r = s[right];
            right++;
            if(need.count(r)){
                window[r]++;
                if(window[r]==need[r]){
                    valid++;
                }
            }
            while(valid == need.size()){
                if(right-left < len){
                    start = left;
                    len = right - left;
                }
                char l = s[left];
                left++;
                if(need.count(l)){
                    if(window[l]==need[l]){
                        valid--;
                    }
                    window[l]--;
                }
            }

        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};

// main函数用于测试
int main() {
    Solution solution;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test case 1: " << solution.minWindow(s1, t1) << endl; // 应输出 "BANC"

    string s2 = "a";
    string t2 = "a";
    cout << "Test case 2: " << solution.minWindow(s2, t2) << endl; // 应输出 "a"

    string s3 = "a";
    string t3 = "aa";
    cout << "Test case 3: " << solution.minWindow(s3, t3) << endl; // 应输出 ""

    return 0;
}