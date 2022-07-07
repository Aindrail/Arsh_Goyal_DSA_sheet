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
   
        ListNode* mergeKLists(vector<ListNode*>& lists) {
      auto comp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
      };
      priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
      
      ListNode dummy(0);
      ListNode* tail = &dummy;
      for (ListNode* l : lists) {
        if (l) q.push(l);
      }
      
      while (!q.empty()) {
        tail = tail->next = q.top();
        q.pop();
        if (tail->next) q.push(tail->next);
      }
      return dummy.next;
    }
    
};