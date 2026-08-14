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
        Node* dummyHead = new Node(0);
        Node* currentNode = dummyHead;

        unordered_map<Node*, Node*>originalToCopy;

        for(Node* original = head; original != nullptr; original =original->next){
            Node* copyNode = new Node(original->val);

            currentNode->next = copyNode;
            currentNode = copyNode;

            originalToCopy[original] = copyNode;
        }

        for(Node* original = head; original!= nullptr; original=original->next){
            if(original ->random != nullptr){
                originalToCopy[original]->random = originalToCopy[original->random];
            } else{
                originalToCopy[original]->random = nullptr;
            }
        }
        return dummyHead->next;
    }
};
