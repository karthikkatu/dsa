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


const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}