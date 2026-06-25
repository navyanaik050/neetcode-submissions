class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for(int i=0; i<n; i++){
            int cnt =0;
            for(int j=i; j<n; j++){
                cnt += nums[j];
                res = max(res, cnt);
            }
        }
        return res;
    }
};
