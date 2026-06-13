class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int middle;
        while (low <= high){
            middle = (low+high)/2;
            if (nums[middle] == target){
                return middle;
            } else if (target > nums[middle]) low = middle+1;
            else high = middle-1;
        }
        return -1;
    }
};
