class Solution {
public:
      long long allsubarrays(vector<int>& nums)
        {
            long long l=0;
         long long r =0;
        long long n= nums.size();
        long long count =0;
        while(r<n)
        {
            count+=(r-l+1);
            r++;
        }
        return count;
            
        }
        long long subarrayslessthank(vector<int>& nums ,int k)
        {
             long long l=0;
            long long r =0;
            long long n= nums.size();
            long long count =0;
            long long mx = *max_element(nums.begin(),nums.end());
            long long freq = 0;
            while(r<n)
           {
             if(nums[r]==mx)
                {
                    freq++;
                }
             while(freq>=k)
             {
                if(nums[l]==mx)
                {
                    freq--;
                }
                l++;

             }
             count+=(r-l+1);
             r++;
           }
        return count;
        }

    long long countSubarrays(vector<int>& nums, int k) {
        return (allsubarrays(nums) -subarrayslessthank(nums,k));

    }
};