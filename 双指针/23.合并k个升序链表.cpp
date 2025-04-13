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
#include<vector>
#include<queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq(cmp);

        for(ListNode* head : lists){
            if(head!=nullptr){
                pq.push(head);
            }
        }

        while(!pq.empty()){
            ListNode* node = pq.top();
            p->next = node;
            pq.pop();
            if(node->next!=nullptr){
                pq.push(node->next);
            }
            p = p->next;
        }
            return dummy->next;
    }
};

int main(){

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    
    vector<ListNode*>lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution solution;
    ListNode* mergeKlists = solution.mergeKLists(lists);
    while(mergeKlists!=nullptr) {
        cout<<mergeKlists->val<<"-";
        mergeKlists = mergeKlists->next;
    }
    return 0;

}