/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* pA = list1;
        ListNode* pB = list2;

        while(pA != nullptr && pB != nullptr) {
            if(pA->val > pB->val){
                p->next = pB;
                pB = pB->next;
            }
            else {
                p->next = pA;
                pA = pA->next;
            }
            p = p->next;
        }
        if(pA == nullptr){
            p->next = pB;
        }
        if(pB == nullptr){
            p->next = pA;
        }
        return dummy->next;
    }
};

int main() {
        // 创建链表1: 1->2->4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    
    // 创建链表2: 1->3->4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    // 输出合并后的链表: 1->1->2->3->4->4
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    
    return 0;

}