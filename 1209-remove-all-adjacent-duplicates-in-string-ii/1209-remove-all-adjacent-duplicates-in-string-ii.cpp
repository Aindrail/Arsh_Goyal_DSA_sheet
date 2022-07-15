class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto &i : s ){
            if(!st.empty() && st.top().first == i){
                int count = st.top().second;
                if(count==k-1) st.pop();
                    else{
                       st.pop();
                st.push({i,count+1}); 
                    }
                
            }
            else{
                st.push({i,1});

            }
        }
        string ans;
      if(st.empty()) return ans;
         
        
        else{
            
        
           
            while(!st.empty()){
                int c = st.top().second;
                while(c--)
                ans+=st.top().first;
                st.pop();
            }
        }
         reverse(ans.begin(), ans.end());
        return ans;
    }
};