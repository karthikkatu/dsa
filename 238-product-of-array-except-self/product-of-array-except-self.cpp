class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> ans(n, 0);

    long long product = 1;
    int zeroCount = 0;
    int zeroIndex = -1;

    // Calculate product of non-zero elements
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zeroCount++;
            zeroIndex = i;
        } else {
            product *= nums[i];
        }
    }

    // Case 1: More than one zero
    if (zeroCount > 1) {
        return ans;  // all elements remain 0
    }

    // Case 2: Exactly one zero
    if (zeroCount == 1) {
        ans[zeroIndex] = product;
        return ans;
    }

    // Case 3: No zeros
    for (int i = 0; i < n; i++) {
        ans[i] = product / nums[i];
    }

    return ans;
    }
};