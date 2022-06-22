class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
       if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        
            for(int i =0; i<nums.size()-2;i++){
                if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                    int left = i+1;
                    int right = nums.size()-1;
                    int target = 0-nums[i];
                    while(left<right){
                        if(nums[left]+nums[right]==target){
                             vector<int> triplet;
                            triplet.push_back(nums[i]);
                            triplet.push_back(nums[left]);
                            triplet.push_back(nums[right]);
                            ans.push_back(triplet);
                            while(left<right && nums[right]==nums[right-1]){
                                right--;
                            }
                            while(left<right && nums[left]==nums[left+1]){
                                left++;
                            }
                            right--; left++;
                        }
                        else if(nums[left]+nums[right]>target)
                            right--;
                           
                            
                        
                        else 
                            left++;
                    }
                }
            }
        
        return ans;
    }
};
// vector<vector<int>> res; 
//         sort(num.begin(), num.end()); 

//         for (int i = 0; i < (int)(num.size())-2; i++) {
            
//             if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
//                 int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
//                 while (lo < hi) {
//                     if (num[lo] + num[hi] == sum) {
                        
//                         vector<int> temp; 
//                         temp.push_back(num[i]); 
//                         temp.push_back(num[lo]); 
//                         temp.push_back(num[hi]); 
//                         res.push_back(temp);
                        
//                         while (lo < hi && num[lo] == num[lo+1]) lo++;
//                         while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
//                         lo++; hi--;
//                     } 
//                     else if (num[lo] + num[hi] < sum) lo++;
//                     else hi--;
//                }
//             }
//         }
//         return res;

