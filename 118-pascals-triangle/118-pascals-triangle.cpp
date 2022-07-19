class Solution {
public:
    vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans(numRows);
//         for(int i =0;i<numRows;i++){
// ans[i].resize(i+1);
//             ans[i][i]=ans[i][0]=1;
            
//             for(int j=1;j<i;j++){
// ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
//             }
            
//         }
        
//         return ans;
        vector<vector<int>> rows(numRows);
        if(numRows==1){
            rows[0].push_back(1);
            return rows;
        }else{
            rows[0].push_back(1);
            rows[1].push_back(1);
            rows[1].push_back(1);
            for(int i=2;i<numRows;i++){
                rows[i].push_back(1);
                for(int j=2;j<=i;j++){
                    rows[i].push_back(rows[i-1][j-1]+rows[i-1][j-2]);
                }
                rows[i].push_back(1);
            }
        }
        return rows;
        
    }
};