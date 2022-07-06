// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node* swapNode(Node* cur, Node *next)
    {
        cur->next = next->next; 
        next->next = cur;
        return next;
    }
    Node *zigZag(Node* head)
    {
        if(!head->next)
        return head;
        Node* temp=head,*prev=NULL;
        bool inc=true;
        while(temp->next)
        {
            if(inc)
            {
                if(temp->data > temp->next->data)
                {
                    if(!prev)
                    {
                        head=swapNode(temp,temp->next);
                        prev=head;
                        temp=head->next;
                    }
                    else
                    {
                        prev->next=swapNode(temp,temp->next);
                        prev=prev->next;
                        temp = prev->next;
                    }
                }
                else
                {
                    prev=temp;
                    temp=temp->next;
                }
                inc=false;
            }
            else
            {
               if(temp->data < temp->next->data) 
               {
                   prev->next=swapNode(temp,temp->next);
                   prev=prev->next;
                   temp = prev->next;
               }
               else
                {
                    prev=temp;
                    temp=temp->next;
                }
               inc=true;
            }
        }
        return head;
    }

};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends