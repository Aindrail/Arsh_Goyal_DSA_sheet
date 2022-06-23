int di[]={-1,0,1,0} ; 
int dj[]={0,-1,0,1};
class Solution {
    
    bool explore(vector<vector<char>> & board, int i , int j , int si, string word ){
        
        if(si == word.length())return true;
        // if(board[i][j]==word[si]) return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size()){
            return false;
        }
         if(board[i][j]!=word[si]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        for(int I=0; I<4 ;I++){
           bool res= explore(board,i+di[I],j+dj[I],si+1,word);
            if(res) {
                board[i][j]=temp;
                return true;
            }
        }
        board[i][j]=temp;
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for( int i =0; i<row; i++){
            for( int j =0 ; j<col; j++ ){
                if(board[i][j]!=word[0])continue;
                bool res = explore(board,i,j,0,word);
                if(res)
                    return res;
            }

        } return false;
    }
};