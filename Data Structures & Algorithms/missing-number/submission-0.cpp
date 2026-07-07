class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorRes = n;
        for(int i=0; i<n; i++){
            xorRes ^= i ^ nums[i];
        }
        return xorRes;
        
    }
};
