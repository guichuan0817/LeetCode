#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            unordered_map<char, int>need;
            unordered_map<char, int>window;
            for(char c : p){
                need[c]++;
            }
            int left = 0;
            int right = 0;
            int valid = 0; 
            vector<int>res; 
            while(right < s.size()){
                char c = s[right];
                right++;
                if(need.count(c)){
                    window[c]++;
                    if(window[c] == need[c]){
                        valid++;
                    }
                }
                while(right-left >= need.size()){
                    if(valid == need.size()){
                        res.push_back(left);
                    }
                    char d = s[left];
                    left++;
                    if(need.count(d)){
                        if(window[d] == need[d]){
                            valid--;
                        }
                        window[d]--;
                    }

                }
            }
            return res;
    }
};

int main() {
    Solution solution;
    string s, p;
    
    cout << "输入主字符串 s: ";
    cin >> s;
    cout << "输入目标字符串 p: ";
    cin >> p;
    
    vector<int> indices = solution.findAnagrams(s, p);
    
    cout << "异位词子串的起始索引: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}