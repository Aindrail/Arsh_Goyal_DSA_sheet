class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> product (nums.size()) ;
        int p = 1;
      
        for(int i = 0 ; i<nums.size(); i++){
            product[i] = p;
            p*=nums[i];
        }
       
        p =1;
        for( int i = nums.size()-1 ; i>=0; i--){
            product[i] *= p;
            p*=nums[i];
        }
        return product;
    }
};