
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int m = len / d;

                    for (int r = 0; r < d; r++) {
                        for (int t = 0; t < m / 2; t++) {
                            if (s[i + r + t * d] != s[i + r + (m - 1 - t) * d]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][i + len - 1] = min(cost[i][i + len - 1], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int end = 2 * parts; end <= n; end++) {
                for (int start = 2 * (parts - 1); start <= end - 2; start++) {
                    if (dp[parts - 1][start] != INF) {
                        dp[parts][end] = min(
                            dp[parts][end],
                            dp[parts - 1][start] + cost[start][end - 1]
                        );
                    }
                }
            }
        }

        return dp[k][n];
    }
};
