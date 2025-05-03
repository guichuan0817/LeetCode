#include<iostream>
#include<vector>

using namespace std;


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;      // 跳跃次数
        int currentEnd = 0;  // 当前跳跃能到达的最远位置
        int farthest = 0;    // 所有可能位置中最远的
        
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            
            // 到达当前跳跃的边界
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // 如果已经可以到达终点
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test case 1: " << solution.jump(nums1) << " jumps" << endl;
    
    // 测试用例2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test case 2: " << solution.jump(nums2) << " jumps" << endl;
    
    // 测试用例3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    cout << "Test case 3: " << solution.jump(nums3) << " jumps" << endl;
    
    // 测试用例4
    vector<int> nums4 = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    cout << "Test case 4: " << solution.jump(nums4) << " jumps" << endl;
    
    // 测试用例5 (单元素数组)
    vector<int> nums5 = {0};
    cout << "Test case 5: " << solution.jump(nums5) << " jumps" << endl;
    
    return 0;
}