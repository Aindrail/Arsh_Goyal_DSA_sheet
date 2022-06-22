class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // map<int,int> count_rem;
        vector<int> count_rem (k,0);
        count_rem[0]=1;
        int sum =0;
        int ans =0;
        for(int i =0 ; i<nums.size(); i++){
            int rem;
            sum+=nums[i];
            rem= sum%k;
            if(rem<0){
                rem+=k;
            }
            if(count_rem[rem]!=0){
                ans+=count_rem[rem];
                count_rem[rem]++;
            }
            else{
                count_rem[rem]++;
            }
            // ans+=count_rem[rem]; for map
            // count_rem[rem]+=1;
        }
        return ans;
    }
};