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
    //here what we did ki apan first madye fast pointer tya apan n parynat anala nanter apan slow pointer the fat null hoii parynat nela then delete then return 
    //remmember 1st ki apan dummy ready kela 
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* slow=dummy;
        ListNode* fast=dummy;

        for(int i=0;i<=n;i++){
            fast=fast->next;
        }

        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;

        return dummy->next;
        

    }
};
