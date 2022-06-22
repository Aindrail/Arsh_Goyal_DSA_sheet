class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int,int> count_sum;
//         count_sum[0]++;
//         int ans = 0;
//         int sum=0;
//         for( int i =0; i<nums.size(); i++){
//            sum+=nums[i];
//             int req = sum-k;
//             if(count_sum.find(req)!=count_sum.end())
//                 ans+=count_sum[req];
            
//             count_sum[sum]++;
//         }
//         return ans;
        int ans=0,sm=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            int x=sm;
            if(mp.find(x-k)!=mp.end())
            ans+=mp[x-k];
            mp[x]++;
        }
        return ans;
    }
};