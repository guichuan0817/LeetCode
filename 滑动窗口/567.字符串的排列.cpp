#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
    // 判断 s2 中是否存在 s1 的排列
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>need;
        unordered_map<char, int>window;
        for(char c: s1){
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;

        while(right <  s2.size()){
            char c = s2[right];
            right++;
            // 进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            // 判断左侧窗口是否要收缩
            while(right-left >= s1.size()){
                // 在这里判断是否找到了合法的子串
                if(valid == need.size()){
                    return true;
                }
                char d = s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    window[d]--;
                    if(window[d] == need[d]){
                        valid--;
                    }
                }

            }
        }
        // 未找到符合条件的子串
        return false;      
    }
};

int main() {
    // 测试用例
    Solution solution;
    string s1, s2;
    
    cout << "输入第一个字符串 s1: ";
    cin >> s1;
    cout << "输入第二个字符串 s2: ";
    cin >> s2;
    
    bool result = solution.checkInclusion(s1, s2);
    
    cout << "s2" << (result ? " 包含 " : " 不包含 ") 
         << "s1 的排列: " << boolalpha << result << endl;
    
    return 0;
}