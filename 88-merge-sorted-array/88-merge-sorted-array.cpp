class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = n+m-1;
        n--;m--;
        while(n>=0){
           if(m==-1||nums2[n]>=nums1[m]) nums1[last--]=nums2[n--];
            else nums1[last--] = nums1[m--];
        }
    }
};