class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0, mid =0;
        while(mid<nums.size()){
            if(nums[mid]!=0){
                swap(nums[left],nums[mid]);
            left++;
                mid++;
            }
            else
            mid++;
                
        }
    }
};