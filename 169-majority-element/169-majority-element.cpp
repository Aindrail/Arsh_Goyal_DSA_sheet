class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;int curr;
        for(int temp : nums){
            if(count==0){
                curr=temp;
                
            }
            if(curr==temp) count++;
                else
                    count--;
        }
        return curr;
    }
};