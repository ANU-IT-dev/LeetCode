

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + k < n) ? rank[a + k] : -1;
                int y = (b + k < n) ? rank[b + k] : -1;

                return x < y;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                    (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h])
                h++;

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int mx = 0;

            if (i > 0)
                mx = max(mx, lcp[i]);

            if (i + 1 < n)
                mx = max(mx, lcp[i + 1]);

            int len = mx + 1;

            if (len <= n - sa[i])
                ans = min(ans, len);
        }

        return ans;
    }
};
