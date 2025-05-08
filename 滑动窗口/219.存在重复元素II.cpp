#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        unordered_map<int, int>windowCharCount;

        while(right < nums.size()){
            char c = nums[right];
            if(windowCharCount[c]>0){
                return true;
            }
            windowCharCount[c]++;
            right++;

            while(right - left > k){
                char d = nums[left];
                windowCharCount[d]--;
                left++;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    cout << "Test case 1: " << (solution.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << endl;  // 预期输出: true
    
    // 测试用例2
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1;
    cout << "Test case 2: " << (solution.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << endl;  // 预期输出: true
    
    // 测试用例3
    vector<int> nums3 = {1,2,3,1,2,3};
    int k3 = 2;
    cout << "Test case 3: " << (solution.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << endl;  // 预期输出: false
    
    // 测试用例4 - 空数组
    vector<int> nums4 = {};
    int k4 = 0;
    cout << "Test case 4: " << (solution.containsNearbyDuplicate(nums4, k4) ? "true" : "false") << endl;  // 预期输出: false
    
    // 测试用例5 - 单个元素
    vector<int> nums5 = {1};
    int k5 = 1;
    cout << "Test case 5: " << (solution.containsNearbyDuplicate(nums5, k5) ? "true" : "false") << endl;  // 预期输出: false
    
    return 0;
}