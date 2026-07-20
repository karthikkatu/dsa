class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        char slope = 'x';
        int u = 0;
        int d = 0;
        int n = nums.size();

        for(int i=1;i<n;i++) {
            if(nums[i-1]<nums[i]) {
                if(slope != 'u') {
                    u++;
                    slope = 'u';
                }
            } else if(nums[i-1]>nums[i]) {
                if(slope != 'd') {
                    d++;
                    slope = 'd';
                }
            }
        }
        // cout<<u<<" "<<d<<endl;
        return d+u+1;
    }
};