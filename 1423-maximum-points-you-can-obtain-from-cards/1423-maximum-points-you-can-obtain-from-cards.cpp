class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size()-1;
        int ans = INT_MIN;
        int temp = 0;
        for( int i = 0 ; i<=k ; i++){
            if(i==0){
                for( int j =0 ; j<k ; j++){
                    temp +=card[n-j];
                }
            }
            else{
                temp-=card[n-k+i];
                temp+=card[i-1];
            }
           
            ans = max(ans, temp);
        }
        return ans;
    }
};