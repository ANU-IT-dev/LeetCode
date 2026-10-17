
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> v;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            v.push_back({sum, nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[v[i][2]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (pos[i] != i) {
                int j = pos[i];
                swap(pos[i], pos[j]);
                swaps++;
            }
        }

        return swaps;
    }
};
