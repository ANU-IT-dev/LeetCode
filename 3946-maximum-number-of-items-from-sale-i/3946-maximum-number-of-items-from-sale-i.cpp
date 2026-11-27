
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> w(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) {
                    w[i]++;
                }
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            int p = items[i][1];
            vector<int> ndp = dp;

            for(int r = 0; r < p && r <= budget; r++) {
                int best = NEG;

                for(int b = r; b <= budget; b += p) {
                    if(b >= p && dp[b - p] != NEG) {
                        best = max(best, dp[b - p] - (b - r) / p);
                    }

                    if(best != NEG) {
                        ndp[b] = max(ndp[b], w[i] + (b - r) / p + 1 + best);
                    }
                }
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
