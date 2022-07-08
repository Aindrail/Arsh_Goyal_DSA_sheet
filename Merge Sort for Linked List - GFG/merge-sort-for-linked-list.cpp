// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    Node* findHead(Node* head){
        Node* fast = head->next;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
        
    }
    
    Node* merge(Node* r, Node* l){
        if(r==NULL) return l;
        if(l==NULL) return r;
        Node* temp = new Node(0);
        Node* ans = temp;
        while(l!=NULL && r!=NULL){
            if(l->data<r->data){
                ans->next = l;
                ans = l;
                l= l->next;
                
            }
            else{
                ans->next = r;
                ans = r;
                r= r->next;
                
            }
        }
        while(l!=NULL){
            ans->next = l;
                ans = l;
                l= l->next;
        }
        while(r!=NULL){
            ans->next = r;
            ans = r;
            r= r->next;
        }
       temp = temp->next;
       return temp;
    }
    
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        Node* mid = findHead(head);
        Node* right = mid->next;
        mid->next = NULL;
        Node* left = head;
 
        left = mergeSort(left);
        right = mergeSort(right);
        Node* ans = merge(right , left);
        
        return ans ;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends