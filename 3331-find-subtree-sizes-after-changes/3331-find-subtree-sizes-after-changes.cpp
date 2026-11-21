class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);
        vector<int> old(n);

        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {
                old[u] = last[c];

                if (last[c] != -1) {
                    newParent[u] = last[c];
                }

                last[c] = u;

                st.push({u, 1});

                for (int i = adj[u].size() - 1; i >= 0; i--) {
                    st.push({adj[u][i], 0});
                }
            }
            else {
                last[c] = old[u];
            }
        }

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> order;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : newAdj[u]) {
                q.push(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (newParent[u] != -1) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};