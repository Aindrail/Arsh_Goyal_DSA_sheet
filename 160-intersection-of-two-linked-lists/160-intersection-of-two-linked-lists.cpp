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
        if(headA==NULL || headB==NULL) return NULL;
        ListNode * A = headA, *B = headB;
        while(A!=B){
            if(A==NULL){
                A=headA;
            }else{
               A=A->next;  
            }
            if(B==NULL){
                B=headB;

            }
           else
            B=B->next;
        }
        return A;
    }
};