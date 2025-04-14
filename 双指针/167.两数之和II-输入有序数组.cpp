#include<iostream>
#include<vector>

using namespace std;

//只要数组有序，就应该想到双指针技巧
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 一左一右两个指针相向而行
        int right = numbers.size()-1;
        int left = 0;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                // 题目要求的索引是从 1 开始的
                return vector<int>{left+1, right+1};
            }
            else if(sum > target){
                right--;
            }
            else if(sum < target){
                left++;
            }
        }
        return vector<int>{-1,-1};      
    }
};

int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int>res = solution.twoSum(nums, target);
    cout<<'['<<res[0]<<','<<res[1]<<']'<<endl;
    
}