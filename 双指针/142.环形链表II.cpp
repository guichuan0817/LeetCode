/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 第一步：检测是否有环
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                break;  // 相遇点，说明有环
            }
        }
        
        // 如果没有环
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        
        // 第二步：找到环的起始点
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;  // 环的起始点
    }
};

// 辅助函数：创建链表
ListNode* createLinkedListWithCycle(int arr[], int n, int pos) {
    if (n == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
        if (i == pos) {
            cycleNode = current;//cycleNode指针用于标记环的起始节点
        }
    }
    //如果pos不是-1（表示需要形成环）：将最后一个节点的next指向之前记录的环起始节点
    if (pos != -1) {
        current->next = cycleNode;
    }
    
    return head;
}

// 测试代码
int main() {
    Solution solution;
    
    // 测试用例1：有环
    int arr1[] = {3, 2, 0, -4};
    int pos1 = 1;
    ListNode* head1 = createLinkedListWithCycle(arr1, 4, pos1);
    ListNode* result1 = solution.detectCycle(head1);
    if (result1 != nullptr) {
        std::cout << "Test case 1: Cycle starts at node with value " << result1->val << std::endl;
    } else {
        std::cout << "Test case 1: No cycle" << std::endl;
    }
    
    // 测试用例2：无环
    int arr2[] = {1, 2};
    int pos2 = -1;
    ListNode* head2 = createLinkedListWithCycle(arr2, 2, pos2);
    ListNode* result2 = solution.detectCycle(head2);
    if (result2 != nullptr) {
        std::cout << "Test case 2: Cycle starts at node with value " << result2->val << std::endl;
    } else {
        std::cout << "Test case 2: No cycle" << std::endl;
    }
    
    // 测试用例3：单个节点无环
    int arr3[] = {1};
    int pos3 = -1;
    ListNode* head3 = createLinkedListWithCycle(arr3, 1, pos3);
    ListNode* result3 = solution.detectCycle(head3);
    if (result3 != nullptr) {
        std::cout << "Test case 3: Cycle starts at node with value " << result3->val << std::endl;
    } else {
        std::cout << "Test case 3: No cycle" << std::endl;
    }
    return 0;
}