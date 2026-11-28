
class Solution {
public:
    struct Node {
        long long price;
        int type;
        long long cnt;
    };

    struct cmp {
        bool operator()(const Node& a, const Node& b) const {
            return a.price * b.type > b.price * a.type;
        }
    };

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0;

        vector<int> freq(n + 1, 0);

        for (auto& x : items) {
            freq[x[0]]++;
            mx = max(mx, x[0]);
        }

        vector<int> gain(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        priority_queue<Node, vector<Node>, cmp> pq;

        for (auto& x : items) {
            int f = x[0];
            int p = x[1];

            if (gain[f] > 0)
                pq.push({p, 2, gain[f]});
            else
                pq.push({p, 1, 0});
        }

        long long ans = 0;
        long long rem = budget;

        while (!pq.empty() && rem > 0) {
            auto cur = pq.top();
            pq.pop();

            long long p = cur.price;

            if (cur.type == 2) {
                long long take = min(cur.cnt, rem / p);

                ans += 2 * take;
                rem -= take * p;

                pq.push({p, 1, 0});
            }
            else {
                long long take = rem / p;

                ans += take;
                rem -= take * p;

                break;
            }
        }

        return (int)ans;
    }
};
