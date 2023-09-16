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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* curr=head;
        int ctr=1;
        while(curr->next!=NULL){
            ctr++;
            curr=curr->next;
        }
        if(ctr==n){
            head=head->next;
            return head;
        }
        cout<<ctr;
        int fin=(ctr-n)+1;
        int fromstart=1;
        ListNode* current=head;
        ListNode* prev=head;
        while(fromstart!=fin){
            prev=current;
            current=current->next;
            fromstart++;
        }
        prev->next=current->next;
        return head;

        
    }
};
