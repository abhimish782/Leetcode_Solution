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

 // Insertion Sort O(n^2) time and O(1) space
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
       ListNode* ans=new ListNode(-1);
       ListNode* ptr=head;
       ListNode* dummy=ans;
       while(ptr!=nullptr){
           while(ans->next!=nullptr&&ans->next->val<ptr->val){
               ans=ans->next;
           }
           ListNode* temp=ans->next;
           ans->next=ptr;
           ListNode* temp2=ptr->next;
           ptr->next=temp;

           ptr=temp2;
           ans=dummy;
       }
       return dummy->next;
    }
};
// Merge Sort O(nlogn) time and O(n) inherent stack space
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* secondhalf=getMiddle(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(secondhalf);
        return Merge(left,right);
    }
    private:
    ListNode* getMiddle(ListNode* head){
        ListNode* fast=head,*slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(head->next!=slow){
            head=head->next;
        }
        head->next=nullptr;
        return slow;
    }
    ListNode* Merge(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* res=nullptr;
        if(list1->val<=list2->val){
            res=list1;
            res->next=Merge(list1->next,list2);
        }
        else{
            res=list2;
            res->next=Merge(list1,list2->next);
        }
        return res;
    }
};
