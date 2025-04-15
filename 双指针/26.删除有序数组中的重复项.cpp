#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int fast = 0;
        int slow = 0;
        while(fast < nums.size()){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};

int main() {
    Solution solution;
    // 测试用例1
    vector<int> nums1 = {1, 1, 2};
    cout << "原始数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    
    int k1 = solution.removeDuplicates(nums1);
    cout << "新长度: " << k1 << endl;
    cout << "修改后的数组(前" << k1 << "个元素): ";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl << endl;
    
    // 测试用例2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "原始数组: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    
    int k2 = solution.removeDuplicates(nums2);
    cout << "新长度: " << k2 << endl;
    cout << "修改后的数组(前" << k2 << "个元素): ";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    
    return 0;
}