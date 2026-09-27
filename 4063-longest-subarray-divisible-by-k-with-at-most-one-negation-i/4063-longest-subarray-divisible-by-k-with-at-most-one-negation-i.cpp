class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int left = 0; left < n; left++) {
            
            set<int>st;
            long long curr = 0;

            for (int right = left; right < n; right++) {
                curr += nums[right];
                long long rem = (long long)((nums[right]*2)%k+k)%k;
                st.insert(rem);
                long long sum = (long long)(curr%k+k)%k;
                if(sum==0 || st.find(sum)!= st.end())
                {
                    ans = max(ans,(right-left+1));
                }

            }
    }
    return ans;
    }
    
};