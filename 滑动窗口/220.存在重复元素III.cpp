#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        set<long> window;
        int left = 0, right = 0;
        while (right < nums.size()) {
            // 为了防止 i == j，所以在扩大窗口之前先判断是否有符合题意的索引对 (i, j)
            // 查找略大于 nums[right] 的那个元素
            auto ceiling = window.lower_bound((long)nums[right]);
            //lower_bound 是 std::set 的成员函数，返回一个迭代器，指向集合中第一个大于或等于 nums[right] 的元素。
            if (ceiling != window.end() && *ceiling - nums[right] <= t) {
                return true;
            }
            // 查找略小于 nums[right] 的那个元素
            auto floor = ceiling;
            if (floor != window.begin()) {
                floor--;
                if (nums[right] - *floor <= t) {
                    return true;
                }
            }

            // 扩大窗口
            window.insert(nums[right]);
            right++;

            while (right - left > k) {
                // 缩小窗口
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,2,3,1};
    cout << (sol.containsNearbyAlmostDuplicate(nums1, 3, 0)? "true":"false")<< endl; // true
    
    vector<int> nums2 = {1,5,9,1,5,9};
    cout << (sol.containsNearbyAlmostDuplicate(nums2, 2, 3)? "true":"false") << endl; // false
    
    vector<int> nums3 = {8,7,15,1,6};
    cout << (sol.containsNearbyAlmostDuplicate(nums3, 1, 3)? "true":"false")<< endl; // true
    
    return 0;
}