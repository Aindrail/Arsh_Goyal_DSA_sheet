class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int minPrice = INT_MAX;
        for(int i =0 ; i<prices.size();i++){
         minPrice = min(minPrice,prices[i]);
            ans = max(ans,prices[i]-minPrice);
        }
        return ans;
    }
    
};