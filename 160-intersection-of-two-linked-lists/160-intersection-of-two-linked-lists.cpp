/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     ListNode* d1 = head1;
//     ListNode* d2 = head2;
    
//     while(d1 != d2) {
//         d1 = d1 == NULL? head2:d1->next;
//         d2 = d2 == NULL? head1:d2->next;
//     }
    
//     return d1;
//     }
        stack<ListNode *> sA, sB;
        ListNode *ptrA, *ptrB, *ptrI;
        ptrA = headA; ptrB = headB;
        while(ptrA){
            sA.push(ptrA);
            ptrA = ptrA->next;
        }
        while(ptrB){
                sB.push(ptrB);
            ptrB = ptrB->next;
        }
        if(sB.top() != sA.top()) return NULL;
        // printf("A B %d %d\n", sA.top(), sB.top());
        //sA.pop(); sB.pop();
        int nA = sA.size(); 
        int nB = sB.size();
        int n = min(nA, nB);
        //printf("%d %d %d\n", nA, nB, n);
        for(int i=1; i<=n; i++){
            if(sA.top() == sB.top()){
                //printf("A B %d %d\n", sA.top(), sB.top());
                ptrI = sA.top();
                sA.pop();
                sB.pop();
            }
            else {
                break;
            }
        }
        return(ptrI);
    }
};