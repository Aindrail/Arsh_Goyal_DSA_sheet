class Solution {
public:
    int countAsterisks(string s) {
        bool count_bar= 0;int countA=0, last;
        for(int i =0; i<s.length();i++){
             if(s[i]=='|') {
                 last = i;
                 count_bar=!count_bar;
             }
            
            if(count_bar==false){
                if(s[i]=='*') countA++;
            }
        }
        if(count_bar%2==1){
        for(int i = last+1; i<s.length(); i++){
            if(s[i]=='*') countA++;
        }
        }
        return countA;
    }
};