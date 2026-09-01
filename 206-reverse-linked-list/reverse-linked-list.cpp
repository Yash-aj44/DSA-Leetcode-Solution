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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* h2=nullptr;
        while(head!=nullptr){
        ListNode* temp=head;
        head=head->next;
        temp->next=h2;
        h2=temp;
        }
        return h2;

        
    }

        
    
};