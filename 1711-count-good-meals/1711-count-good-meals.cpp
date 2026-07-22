class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        long long ans = 0;

        for (int num : deliciousness) {

            // Check every power of 2
            for (int power = 1; power <= (1 << 21); power <<= 1) {

                int need = power - num;

                if (mp.count(need)) {
                    ans = (ans + mp[need]) % MOD;
                }
            }

            mp[num]++;
        }

        return ans % MOD;
    }
};