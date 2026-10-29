/*class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        

       
    }
};*/


 /*class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<vector<int>> up(17, vector<int>(n));
        vector<int> timer(1, 0);

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer[0]++;
            up[0][u] = p;

            for (int k = 1; k < 17; k++)
                up[k][u] = up[k - 1][up[k - 1][u]];

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer[0]++;
        };

        dfs(0, 0);

        auto isAncestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto lca = [&](int u, int v) {
            if (isAncestor(u, v)) return u;
            if (isAncestor(v, u)) return v;

            for (int k = 16; k >= 0; k--) {
                if (!isAncestor(up[k][u], v))
                    u = up[k][u];
            }
            return up[0][u];
        };

        vector<int> bit(2 * n + 2, 0);

        auto updateBIT = [&](int idx, int val) {
            for (idx++; idx < (int)bit.size(); idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto queryBIT = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            updateBIT(tin[i], mask[i]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                int newMask = 1 << (c - 'a');
                updateBIT(tin[u], mask[u] ^ newMask);
                mask[u] = newMask;
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);

                int pathMask = queryBIT(tin[u]) ^ queryBIT(tin[v]) ^ mask[w];

                if (w != u && w != v)
                    pathMask ^= mask[w];

                ans.push_back(__builtin_popcount((unsigned)pathMask) <= 1);
            }
        }

        return ans;
    }
};*/


class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                               string s, vector<string>& queries) {

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0);
        vector<int> sz(n, 1), heavy(n, -1), order;

        parent[0] = 0;
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            int p = parent[u];

            sz[p] += sz[u];

            if (heavy[p] == -1 || sz[u] > sz[heavy[p]])
                heavy[p] = u;
        }

        vector<int> head(n), pos(n);
        int timer = 0;

        vector<pair<int, int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [u, h] = st.back();
            st.pop_back();

            while (u != -1) {
                head[u] = h;
                pos[u] = timer++;

                for (int v : adj[u]) {
                    if (v != parent[u] && v != heavy[u])
                        st.push_back({v, v});
                }

                u = heavy[u];
            }
        }

        vector<int> seg(4 * n, 0);

        function<void(int,int,int)> build = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = 1 << (s[order[l]] - 'a');
                return;
            }

            int mid = (l + r) / 2;

            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);

            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };

        // Build using HLD positions
        vector<int> base(n);

        for (int i = 0; i < n; i++)
            base[pos[i]] = 1 << (s[i] - 'a');

        function<void(int,int,int)> buildSeg = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = base[l];
                return;
            }

            int mid = (l + r) / 2;

            buildSeg(node * 2, l, mid);
            buildSeg(node * 2 + 1, mid + 1, r);

            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };

        buildSeg(1, 0, n - 1);

        function<void(int,int,int,int,int)> update =
        [&](int node, int l, int r, int idx, int val) {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                update(node * 2, l, mid, idx, val);
            else
                update(node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };

        function<int(int,int,int,int,int)> querySeg =
        [&](int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) / 2;

            return querySeg(node * 2, l, mid, ql, qr) ^
                   querySeg(node * 2 + 1, mid + 1, r, ql, qr);
        };

        auto pathQuery = [&](int u, int v) {
            int mask = 0;

            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);

                mask ^= querySeg(1, 0, n - 1, pos[head[u]], pos[u]);

                u = parent[head[u]];
            }

            if (depth[u] > depth[v])
                swap(u, v);

            mask ^= querySeg(1, 0, n - 1, pos[u], pos[v]);

            return mask;
        };

        vector<bool> ans;

        for (string &q : queries) {
            string type;
            int u, v;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;

                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            }
            else {
                ss >> v;

                int mask = pathQuery(u, v);

                ans.push_back(__builtin_popcount((unsigned)mask) <= 1);
            }
        }

        return ans;
    }
};