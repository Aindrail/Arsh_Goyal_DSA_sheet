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
    bool hasCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        if(head==NULL)
            return false;
        
        if(fast->next !=NULL){
             do{
            
                fast = fast->next->next;
            slow = slow->next;

   
} while( fast != NULL &&fast->next !=NULL && fast!=slow);
}
        
      
        if(fast==NULL || fast->next ==NULL){
return false;
}
        return true;
    }
};