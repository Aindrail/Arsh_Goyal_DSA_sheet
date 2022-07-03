// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    int isPossible(int A[], int pages,int n, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < n; i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int n, int B) 
    {
        //code here
        if (B > n) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i <n; i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid,n, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends