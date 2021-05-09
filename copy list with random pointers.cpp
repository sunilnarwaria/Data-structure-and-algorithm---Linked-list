
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

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        Node *temp1;
        while(temp){
            temp1=new Node(temp->val);
            temp1->next=temp->random;
            temp->random=temp1;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            temp1=temp->random;
            if(temp1->next)
                temp1->random=temp1->next->random;
            else
                temp1->random=temp1->next;
            temp=temp->next;
        }
        temp=head;
        Node *newHead=NULL;
        while(temp) {
            temp1=temp->random;
            temp->random=temp1->next;
            if(temp->next)
                temp1->next=temp->next->random;
            else
                temp1->next=temp->next;
            if(!newHead)
                newHead=temp1;
            temp=temp->next;
        }
        return newHead;
    }
};
