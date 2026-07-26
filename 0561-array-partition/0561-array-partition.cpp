class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // [1,2,2,5,6,6]// [1,2,3,4]
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int sum=0;
        
        for(int i=0; i<n-1; i+=2)
        {
             int minpair=  min(nums[i],nums[i+1]);
            sum+=minpair;
        }
        return sum;

        
    }
};