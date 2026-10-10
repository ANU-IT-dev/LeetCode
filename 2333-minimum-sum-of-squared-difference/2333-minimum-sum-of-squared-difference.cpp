
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> countdiff(100001, 0);

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            countdiff[d]++;
        }

        long long k = (long long)k1 + k2;

        for (int currdiff = 100000; currdiff > 0 && k > 0; currdiff--) {
            int countops = min((long long)countdiff[currdiff], k);
            countdiff[currdiff] -= countops;
            countdiff[currdiff - 1] += countops;
            k -= countops;
        }

        long long result = 0;

        for (int d = 1; d <= 100000; d++) {
            result += 1LL * countdiff[d] * d * d;
        }

        return result;
    }
};