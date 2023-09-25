/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
    unordered_map<Node*, Node*> mp;
    Node *temp, *nhead;
   
    temp = head;
    nhead =new Node(temp->val);
    mp[temp] = nhead;
   
    while (temp->next != NULL) { 
        nhead->next= new Node(temp->next->val);
        temp = temp->next;
        nhead = nhead->next;
        mp[temp] = nhead;
    }
    temp = head;
   
    while (temp != NULL) {
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
   
    return mp[head];
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy= new Node(-1);
        Node* pdummy=dummy;
        Node* nhead=head;
        Node* prev=dummy;
        map<Node*,Node*>m1;
        
        while(nhead!=nullptr){
            pdummy->next=new Node(nhead->val);
            m1[nhead]=pdummy->next;
            prev=pdummy;
            pdummy=pdummy->next;
            nhead=nhead->next;
        }
        dummy=dummy->next;
        Node* temp=head;
        while (temp != NULL) {
        m1[temp]->random = m1[temp->random];
        temp = temp->next;
    }
     return dummy;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create a copy of each node and insert it right after the original node.
        Node* ptr = head;
        while (ptr != nullptr) {
            Node* temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = temp->next;
        }
        
        // Step 2: Update the random pointers for the copied nodes.
        ptr = head;
        while (ptr != nullptr) {
            if (ptr->random != nullptr) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        
        // Step 3: Separate the original and copied lists.
        Node* original = head;
        Node* copy = head->next;
        Node* newHead = copy;
        while (original != nullptr) {
            original->next = copy->next;
            original = original->next;
            if (original != nullptr) {
                copy->next = original->next;
                copy = copy->next;
            }
        }
        
        return newHead;
    }
};
