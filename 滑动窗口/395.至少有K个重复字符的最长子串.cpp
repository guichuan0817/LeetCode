#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;




class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = 0;
        for (int i = 1; i <= 26; i++) {
            // 限制窗口中只能有 i 种不同字符
            len = max(len, logestKLetterSubstr(s, k, i));
        }
        return len;
    }

    // 寻找 s 中含有 count 种字符，且每种字符出现次数都大于 k 的子串
    int logestKLetterSubstr(string s, int k, int count) {
        // 记录答案
        int res = 0;
        // 快慢指针维护滑动窗口，左闭右开区间
        int left = 0, right = 0;
        // 题目说 s 中只有小写字母，所以用大小 26 的数组记录窗口中字符出现的次数
        unordered_map<char,int>windowCount;
        // 记录窗口中存在几种不同的字符（字符种类）
        int windowUniqueCount = 0;
        // 记录窗口中有几种字符的出现次数达标（大于等于 k）
        int windowValidCount = 0;
        // 滑动窗口代码模板
        while (right < s.length()) {
            // 移入字符，扩大窗口
            char c = s[right];
            if (windowCount[c] == 0) {
                // 窗口中新增了一种字符
                windowUniqueCount++;
            }
            windowCount[c]++;
            if (windowCount[c] == k) {
                // 窗口中新增了一种达标的字符
                windowValidCount++;
            }
            right++;

            // 当窗口中字符种类大于 count 时，缩小窗口
            while (windowUniqueCount > count) {
                // 移出字符，缩小窗口
                char d = s[left];
                if (windowCount[d] == k) {
                    // 窗口中减少了一种达标的字符
                    windowValidCount--;
                }
                windowCount[d]--;
                if (windowCount[d] == 0) {
                    // 窗口中减少了一种字符
                    windowUniqueCount--;
                }
                left++;
            }

            // 当窗口中字符种类为 count 且每个字符出现次数都满足 k 时，更新答案
            if (windowValidCount == count) {
                res = max(res, right - left);
            }
        }
        return res;
    }
};

void testLongestSubstring(Solution& sol) {
    // 测试用例1: 字符串中所有字符的出现次数都 >= k
    string s1 = "aaabb";
    int k1 = 3;
    int expected1 = 3; // "aaa" 或 "bbb" 的长度是3
    int result1 = sol.longestSubstring(s1, k1);
    cout << "测试用例1: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "预期结果: " << expected1 << ", 实际结果: " << result1 << endl;
    cout << (result1 == expected1 ? "通过" : "失败") << endl << endl;

    // 测试用例2: 字符串中有字符的出现次数 < k
    string s2 = "ababbc";
    int k2 = 2;
    int expected2 = 5; // "ababb" 的长度是5
    int result2 = sol.longestSubstring(s2, k2);
    cout << "测试用例2: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "预期结果: " << expected2 << ", 实际结果: " << result2 << endl;
    cout << (result2 == expected2 ? "通过" : "失败") << endl << endl;

    // 测试用例3: 字符串中所有字符的出现次数都 < k
    string s3 = "abcde";
    int k3 = 2;
    int expected3 = 0; // 没有满足条件的子串
    int result3 = sol.longestSubstring(s3, k3);
    cout << "测试用例3: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "预期结果: " << expected3 << ", 实际结果: " << result3 << endl;
    cout << (result3 == expected3 ? "通过" : "失败") << endl << endl;

    // 测试用例4: 空字符串
    string s4 = "";
    int k4 = 1;
    int expected4 = 0; // 空字符串的长度是0
    int result4 = sol.longestSubstring(s4, k4);
    cout << "测试用例4: s = \"" << s4 << "\", k = " << k4 << endl;
    cout << "预期结果: " << expected4 << ", 实际结果: " << result4 << endl;
    cout << (result4 == expected4 ? "通过" : "失败") << endl << endl;

    // 测试用例5: 字符串中只有一个字符，且出现次数 >= k
    string s5 = "aaaaa";
    int k5 = 5;
    int expected5 = 5; // "aaaaa" 的长度是5
    int result5 = sol.longestSubstring(s5, k5);
    cout << "测试用例5: s = \"" << s5 << "\", k = " << k5 << endl;
    cout << "预期结果: " << expected5 << ", 实际结果: " << result5 << endl;
    cout << (result5 == expected5 ? "通过" : "失败") << endl << endl;
}

int main() {
    Solution solution;
    testLongestSubstring(solution);
    return 0;
}