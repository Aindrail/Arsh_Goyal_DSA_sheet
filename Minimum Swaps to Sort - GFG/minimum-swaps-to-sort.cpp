// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> v;
	    for(int i =0 ; i<nums.size(); i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(), v.end());
	    int count =0;
	    for(int i = 0 ; i<v.size(); i++){
	        pair<int,int> p = v[i];
	        while(p.second!=i){
	            count++;
	            swap(v[p.second],v[i]);
	            p=v[i];
	            
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends