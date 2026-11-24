
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                bool valid = true;

                for(int x = i; x <= j && valid; x++) {
                    for(int y = x + 1; y <= j; y++) {
                        if(__gcd(nums[x], nums[y]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                }

                if(valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
