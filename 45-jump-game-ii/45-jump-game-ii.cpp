class Solution {
public:
    int jump(vector<int>& nums) {
        int mx = INT_MIN;
        int temp=0,ans=0;
        for(int i =0 ; i<nums.size()-1 ; i++){
            mx = max(mx,i+nums[i]);
            if(i==temp){
               
                temp = mx;
                mx=0;
                 ans++;
            }
        }
        return ans;
    }
};