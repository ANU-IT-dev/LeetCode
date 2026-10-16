
class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;

    vector<ll> sum, sq, lazy;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1;
        sq[node] = (sq[node] + 2 * val * sum[node] % MOD
                    + val * val % MOD * len) % MOD;
        sum[node] = (sum[node] + val * len) % MOD;
        lazy[node] += val;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            update(1, 0, n - 1, left, i);
            last[nums[i]] = i;

            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
