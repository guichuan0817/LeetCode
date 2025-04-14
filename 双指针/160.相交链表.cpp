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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // pA 指向 A 链表头结点，pB 指向 B 链表头结点
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB)
        {
            // pA 走一步，如果走到 A 链表末尾，转到 B 链表
            if(pA == nullptr){
                pA = headB;
            }
            else {
                pA = pA->next;
            }
            // pB 走一步，如果走到 B 链表末尾，转到 A 链表
            if(pB == nullptr){
                pB = headA;
            }
            else {
                pB = pB->next;
            }
        }
        return pA;     
    }
};

int main(){
    return 0;
}