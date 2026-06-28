class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j =heights.size()-1;
        int maximum = INT_MIN;
        while (i < j){
            int water = (j-i) * min(heights[i], heights[j]);
            maximum = max(maximum, water);
            if(heights[i] < heights[j]){
                i++;
            } else
                j--;
        }
        return maximum;
    }
};
