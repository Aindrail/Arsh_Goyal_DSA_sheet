class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int>mp;
//         stack<int> st;
//         for(int it : nums2){
//             if(!st.empty() && st.top()<it){
//                  mp[st.top()] = it;
//                 st.pop();
                
//             }
//             st.push(it);
//         }
//         // for (int n : nums1) ans.push_back(m.count(n) ? m[n] : -1);
//         // mp.count[n] ? nums1[]
//             for(int i = 0; i< nums1.size(); i++){
//                 mp.count(nums1[i]) ? nums1[i] = mp[nums1[i]] : nums1[i]= -1;
//             }
//         return nums1;
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : nums1) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};