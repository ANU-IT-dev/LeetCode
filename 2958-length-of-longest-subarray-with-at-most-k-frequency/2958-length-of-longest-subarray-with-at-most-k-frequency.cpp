class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n =nums.size();
        int maxlen =0;
        int length =0;
        unordered_map<int,int>freq;
        while(r<n)
        {
            freq[nums[r]]++;
            while(freq[nums[r]]>k)
            {
                
                freq[nums[l]]--;
                length--;
                l++;
            }
            length++;
            r++;
            maxlen= max(maxlen, length);
        }
        return maxlen;
        
    }
};