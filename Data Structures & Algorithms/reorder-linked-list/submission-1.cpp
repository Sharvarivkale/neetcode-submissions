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
    ListNode* reverse(ListNode* head){
       ListNode* curr=head;
       ListNode* prev=NULL;
       ListNode* future=NULL; 

       while(curr){
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
       }
       return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=slow->next;
        slow->next=NULL;

        temp=reverse(temp);
        ListNode* temp1=head;

        while(temp){
            ListNode* next1=temp1->next;
            ListNode* next2=temp->next;

            temp1->next=temp;
            temp->next=next1;

            temp1=next1;
            temp=next2;

            
        }
    }
};
