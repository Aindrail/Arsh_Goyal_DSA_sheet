// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
    int ans ;
    int i = 0 ;
    while(i<S.length()){
        if(S[i]>='0' && S[i]<='9'){
            st.push(S[i]-'0');
        }
    
    else{
        int ele = st.top();
        st.pop();
        int ele2 = st.top();
        st.pop();
        int cal;
        if(S[i]=='+'){
            cal = ele+ele2;
        }
        else if(S[i]=='-'){
            cal = ele2-ele;
        }
         else if(S[i]=='*'){
             cal = ele2*ele;
         }
          else if(S[i]=='/'){
              cal = ele2/ele;
          }
          
        st.push(cal);
    }
    i++;
    } 
    return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends