

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;
        
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> cnt(n + 1, 0);

        int l = 0, r = 0;
        int active = 0;

        for(auto &it : q) {
            int start = it.first - x;
            int end = it.first;

            while(r < logs.size() && logs[r][1] <= end) {
                int id = logs[r][0];

                if(cnt[id] == 0)
                    active++;

                cnt[id]++;
                r++;
            }

            while(l < r && logs[l][1] < start) {
                int id = logs[l][0];

                cnt[id]--;

                if(cnt[id] == 0)
                    active--;

                l++;
            }

            ans[it.second] = n - active;
        }

        return ans;
    }
};
