class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool flag = true;
            int prevMax = 0;

            for (int i = 0; i < n; i += k) {
                int cnt = 0;

                for (int j = i; j < i + k - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        cnt++;
                    }
                }

                if (cnt > 1 || (cnt == 1 && nums[i] < nums[i + k - 1])) {
                    flag = false;
                    break;
                }

                int mn = nums[i], mx = nums[i];

                for (int j = i + 1; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                if (i > 0 && prevMax > mn) {
                    flag = false;
                    break;
                }

                prevMax = mx;
            }

            if (flag) ans += k;
        }

        return ans;
    }
};