class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];

        bool forward = true, backward = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (s + i) % n)
                forward = false;

            if (nums[i] != (s - i + n) % n)
                backward = false;
        }

        if (forward) {
            if (s == 0) return 0;
            return min(n - s, s + 2);
        }

        if (backward) {
            int k = (s + 1) % n;
            return 1 + min(k, (n - k) % n);
        }

        return -1;
    }
};