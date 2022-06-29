class Solution {
    int merge(vector<int>& nums,int left ,int mid, int right){
//         int count=0;int j = mid+1;
//         for(int i=low; i<=mid;i++){
//             while(j<=high && nums[i] > 2LL*nums[j]){
//                 j++;
//             }
//             count+=j-(mid+1);
//         }
//         vector<int>temp;
//         int left = low, right = mid+1;
//         while(left<=mid && right<=high){
//             if(nums[left]<=nums[right]){
//                 temp.push_back(nums[left++]);
//             }
//             else{
//                 temp.push_back(nums[right++]);
//             }
//         }
//         while(left<=mid){
//             temp.push_back(nums[left++]);
//         }
//         while(right<=high){
//             temp.push_back(nums[right++]);
//         }
        
//         for(int i=0; i<temp.size(); i++){
//             nums[low+i]= temp[i];
//         }
//         // for (int i = low; i <= high; i++) {
//         //      nums[i] = temp[i - low];
//         //    }
//         return count;
        int n = mid - left + 1;
        int m = right - mid;
        int a[n];
        int b[m];
        for(int i=0; i<n; ++i){
            a[i] = nums[i + left];
        }
        for(int i=0; i<m; ++i){
            b[i] = nums[mid + i + 1];
        }
        
        //Counting reverse pairs
        
        // int i=0, j=0, count = 0;
        // while(i<n && j<m){
        //     if((a[i]/2.0) > b[j]){
        //         count += (n - i);
        //         j++;
        //     }else{
        //         i++;
        //     }
        // }
        int i=left, j=mid+1, count = 0;
       
for(; i<=mid;i++){
            while(j<=right && nums[i] > 2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        
        //Merging elements
        
        i = 0, j = 0;
        int k = left;
        while(i < n && j < m){
            if(a[i] < b[j]){
                nums[k++] = a[i];
                ++i;
            }else{
                nums[k++] = b[j];
                ++j;
            }
        }
        while(i < n){
            nums[k++] = a[i];
            ++i;
        }
        while(j < m){
            nums[k++] = b[j];
            ++j;
        }
        return count;
    
    }
    int mergeSort(vector<int>& nums,int low , int high){
        if(low>=high) return 0;
        int ans =0;
        int mid = (low+high)/2;
        ans+=mergeSort(nums,low,mid);
        ans+=mergeSort(nums,mid+1,high);
        ans+=merge(nums,low,mid,high);
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};