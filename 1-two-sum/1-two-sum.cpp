class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> diff;
        // diff.push_back(target-nums[0]);
        for( int i = 0 ; i< nums.size(); i++){
            if( diff.find(nums[i])!= diff.end()){
                ans.push_back(diff[nums[i]]);
                ans.push_back(i);
                
            }
            else{
                // diff.push(target-nums[i],i);
                diff[target-nums[i]] = i;
            }
        }
        return ans;
    }
};