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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=new ListNode(-1);
        ListNode* ansp=ans;
        int len=findLen(head);
        stack<int>reverse;
        ListNode* curr=head;
        int endpoint=len-(len%k);
        int start=0;
        while(start<endpoint){
            reverse.push(head->val);
            start++;
            if(start%k==0){
                while(!reverse.empty()){
                    ans->next=new ListNode(reverse.top());
                    reverse.pop();
                    ans=ans->next;
                }
            }
            head=head->next;
        }
        ans->next=head;
        return ansp->next;
    }
private:
    int findLen(ListNode* head){
        int cnt=0;
        while(head!=nullptr){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
};
