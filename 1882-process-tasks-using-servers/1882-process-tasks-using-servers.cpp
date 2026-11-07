
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;

        priority_queue<pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            while(!busy.empty() && busy.top().first <= time) {
                available.push(busy.top().second);
                busy.pop();
            }

            if(available.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    available.push(busy.top().second);
                    busy.pop();
                }
            }

            auto [weight, id] = available.top();
            available.pop();

            ans[i] = id;

            busy.push({time + tasks[i], {weight, id}});
        }

        return ans;
    }
};

