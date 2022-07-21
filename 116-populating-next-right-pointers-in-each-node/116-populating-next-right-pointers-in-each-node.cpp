/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        auto head = root;
        for(;root;root=root->left){
            for(auto temp = root; temp; temp= temp->next){
                if(temp->left){
                    temp->left->next = temp->right;
                    if(temp->next){
                        temp->right->next = temp->next->left;
                    }
                }else break;
            }
            
        }
        return head;
    }
};