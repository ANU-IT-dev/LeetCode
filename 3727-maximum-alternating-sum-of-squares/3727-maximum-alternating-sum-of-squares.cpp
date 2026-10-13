class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> square;

        for (int i = 0; i < n; i++) {
            long long sqr = 1LL * nums[i] * nums[i];
            square.push_back(sqr);
        }

        sort(square.begin(), square.end());

        for (int i = 0; i < square.size()/2; i++) {
           ans-= square[i];
        }
         for (int i = square.size()/2; i < square.size(); i++) {
           ans+= square[i];
        }


        return ans;
    }
};
