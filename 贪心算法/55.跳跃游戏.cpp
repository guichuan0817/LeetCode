#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        //维护一个变量 farthest，表示当前能到达的最远位置
        int farthest = 0;
        for(int i=0; i<n; i++){
            //如果当前位置超过了farthest，说明无法到达当前位置，返回false
            if(farthest < i){
                return false;
            }
            //更新farthest为当前位置能到达的最远距离（i + nums[i]）和当前farthest中的较大值
            farthest = max(farthest, i+nums[i]);
            // 如果已经可以到达最后一个位置
            if (farthest >= n - 1) {
                return true;
            }
        }
        //如果farthest已经可以覆盖最后一个位置，提前返回true
        return true; 
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test case 1: " << (solution.canJump(nums1) ? "true" : "false") << endl;
    
    // 测试用例2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test case 2: " << (solution.canJump(nums2) ? "true" : "false") << endl;
    
    // 测试用例3
    vector<int> nums3 = {0};
    cout << "Test case 3: " << (solution.canJump(nums3) ? "true" : "false") << endl;
    
    // 测试用例4
    vector<int> nums4 = {2, 5, 0, 0};
    cout << "Test case 4: " << (solution.canJump(nums4) ? "true" : "false") << endl;
    
    return 0;
}