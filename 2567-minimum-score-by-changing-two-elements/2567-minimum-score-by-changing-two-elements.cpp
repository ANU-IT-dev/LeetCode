class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans1; int ans2;int ans3;
        for(int i=0; i<n;i++)
        {
            ans1= (nums[n-1]-nums[2]);
            ans2= (nums[n-2]-nums[1]);
            ans3= nums[n-3]- nums[0];

        }
        return min({ans1,ans2, ans3});
        
    }
};