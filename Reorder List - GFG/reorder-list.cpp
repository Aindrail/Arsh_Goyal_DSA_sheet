// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nexxt;
        
        while(curr){
            nexxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexxt;
        }
        return prev;
    }

void reorderList(Node* head) {
    // Your code here
    if(!head || !(head->next) || !(head->next->next)) return;
        
        //Step1: Find middle node (in case of even length, find first middle node)
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
		//break linked list into 2 (first from start to mid and second from mid+1 to end)
        Node* head2 = slow->next;
        slow->next = NULL;
        
        //Step2: Reverse linked list 2 (from mid+1 to end)
        head2 = reverse(head2);
        
        //Step3: Merge 2 linked lists
        Node* h = head;
        while(head2){
            Node* temp = head2->next;
            head2->next = h->next;
            h ->next = head2;
            head2 = temp;
            h = h->next->next;
        }
}