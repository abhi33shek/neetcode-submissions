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
        if (!head) return nullptr;
        
     
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
        
    
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        
        while (original) {
            original->next = original->next->next;
            copy->next = (copy->next) ? copy->next->next : nullptr;
            original = original->next;
            copy = copy->next;
        }
        
        return copyHead;
    }
};
