class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gsum = INT_MIN;
        int lsum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            lsum += nums[i];

            if(lsum > gsum) {
                gsum = lsum;
            }

            if(lsum < 0) {
                lsum = 0;
            }
        }
        return gsum;
    }
};