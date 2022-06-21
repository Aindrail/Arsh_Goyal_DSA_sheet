class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =0, sell = 0, profit =0;
        for( int i = 1 ; i<prices.size(); i++){
            if(prices[i]>=prices[i-1]){
                sell++;
                if(i==prices.size()-1){
                    profit +=prices[sell]-prices[buy];
                }
                
            }
            else{
                profit +=prices[sell]-prices[buy];
                buy = i;
                sell = i;
                
            }
        }
        return profit;
    }
};