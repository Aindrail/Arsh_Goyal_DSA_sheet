class Solution {
public:
    int maxArea(vector<int>& height) {
        int tempArea = 0, mxArea = 0;
        int left = 0, right = height.size()-1;
        while(left<right)
        {
            tempArea = (right-left)*(min(height[left], height[right]));
            mxArea = max(tempArea, mxArea);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return mxArea;
    }
};