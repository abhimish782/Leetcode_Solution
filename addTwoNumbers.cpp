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


class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nhead=new ListNode(-1);
        ListNode* curr=nhead;
        int carry=0;
        while(l1!=NULL||l2!=NULL||carry!=0){
            int p=l1!=NULL?l1->val:0;
            int q=l2!=NULL?l2->val:0;
            int s=p+q+carry;
            ListNode* node=new ListNode(s%10);
            carry=s/10;
            curr->next=node;
            curr=curr->next;
            l1=l1!=NULL?l1->next:NULL;
            l2=l2!=NULL?l2->next:NULL;
        }
        return nhead->next;
    }
};

class Solution2{
    int carry=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2 && !carry) return NULL;
        ListNode *l3;
        int sum =l1&&l2 ? l1->val+l2->val+carry : l1&&!l2 ? l1->val+carry : !l1&&l2 ? l2->val+carry : carry ;
        carry = sum/10;
        if(sum > 9) sum= sum%10;
        l3= new ListNode(sum);
        l3->next= addTwoNumbers(l1==nullptr ?l1:l1->next,l2==nullptr ?l2: l2->next);
        return l3;
    }
};
