class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans =0 ;
        if(nums.size()==0)return ans;
       
        for(int i = 1;i<nums.size();i++){
            if(nums[ans]!=nums[i]){
                 ans++;
               nums[ans]= nums[i];
               
            } 
        }
        return ans+1;
    }
};