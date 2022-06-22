class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)return ans;
        sort(nums.begin(), nums.end());
        for( int i = 0 ; i<nums.size()-3; i++){
            for( int j = i+1; j<nums.size()-2; j++){
                long sum= target-(long)nums[i]-(long)nums[j];
                int left =j+1, right = nums.size()-1;
                while(left<right){
                    if(nums[left]+nums[right]==sum){
                        vector<int>quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[left]);
                        quad.push_back(nums[right]);
                        ans.push_back(quad);
                        while(left<right && nums[left]==nums[left+1])
                            left++;
                        while(left<right && nums[right]==nums[right-1])
                            right--;
                        left++;right--;
                    }
                    else if(nums[left]+nums[right]<sum) left++;
                    else right--;
                }
               while(j<nums.size()-2 && nums[j]==nums[j+1]) j++; 
            }
             while(i<nums.size()-3 && nums[i]==nums[i+1]) i++; 
        }
        return ans;
    }
};