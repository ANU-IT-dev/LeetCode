class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n= nums.size();
        long long pdt=1;
        int count =0;
        if(k<=1) return 0;
        while(r<n)
        {
            pdt= pdt* nums[r];
            while(pdt>=k)
            {
                pdt/=nums[l];
                l++;
            }
                count+=(r-l+1);
                 r++;
           
        }
        return count;

        
    }
};