#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){
            return 0;
        }
        int fast = 0; 
        int slow = 0;
        while(fast < nums.size()){
            if(nums[fast] != val){
                //注意这里和有序数组去重的解法有一个细节差异，我们这里是先给 nums[slow] 赋值然后再给 slow++，
                //这样可以保证 nums[0..slow-1] 是不包含值为 val 的元素的，最后的结果数组长度就是 slow。
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
        
    }
};

int main() {
    Solution solution;
    // 测试用例1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    cout << "原始数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << "\n要移除的值: " << val1 << endl;
    
    int k1 = solution.removeElement(nums1, val1);
    cout << "新长度: " << k1 << endl;
    cout << "修改后的数组(前" << k1 << "个元素): ";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl << endl;
    
    // 测试用例2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    cout << "原始数组: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << "\n要移除的值: " << val2 << endl;
    
    int k2 = solution.removeElement(nums2, val2);
    cout << "新长度: " << k2 << endl;
    cout << "修改后的数组(前" << k2 << "个元素): ";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    
    return 0;
}