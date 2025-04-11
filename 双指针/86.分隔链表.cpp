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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* p = head;
        ListNode* p1 = dummy1;
        ListNode* p2 = dummy2;

        while(p != nullptr){
            if(p->val < x) {
                p1->next = p;
                p1 = p1->next;
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
            }
             // 不能直接让 p 指针前进，
            // p = p->next
            // 断开原链表中的每个节点的 next 指针
            ListNode* temp = p->next;
            p->next = nullptr;
            p = temp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};

int main(){

        ListNode* head = new ListNode(1);
        head->next = new ListNode(4);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(2);
        head->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next = new ListNode(2);

        int x = 3;
        Solution solution;
        ListNode* partition = solution.partition(head, x);

        while(partition!=nullptr){
            cout<<partition->val<<"-";
            partition = partition->next;
        }

}