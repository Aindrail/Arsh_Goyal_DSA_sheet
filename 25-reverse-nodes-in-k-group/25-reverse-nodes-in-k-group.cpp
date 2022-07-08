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
        if(head==NULL || k==1) return head;
        ListNode* temp = new ListNode(0);
        temp->next= head;
        
        ListNode* curr = temp , *nxt = temp, *pre = temp;
        int size=0;
        while(curr->next!=NULL){
            curr= curr->next;
            size++;
        }
        while(size>=k){
            curr = pre->next;
            nxt = curr->next;
            for(int i = 1 ; i<k ;i++){
                curr->next= nxt->next;
                nxt->next= pre->next;
                pre->next = nxt;
                nxt= curr->next;
            }
            pre = curr;
            size-=k;
        }
        return temp->next;
        
    }
};