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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        // 删除倒数第 n 个，要先找倒数第 n + 1 个节点
        ListNode* del = findNthNode(dummy, n+1);
        del->next = del->next->next;
        return dummy->next;
    }

    ListNode* findNthNode(ListNode* head, int k) {
        
        ListNode* pA = head;
        ListNode* pB = head;
        for(int i = 0; i < k; i++){
            pA = pA->next;
        }
        while(pA != nullptr){
            pA = pA->next;
            pB = pB->next;
        }
        return pB;
    }
};

int main(){
    int n = 2;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    ListNode* removeNthFromEnd = solution.removeNthFromEnd(head, n);
    while(removeNthFromEnd!=nullptr){
        cout<<removeNthFromEnd->val<<"-";
        removeNthFromEnd = removeNthFromEnd->next;
    }
}