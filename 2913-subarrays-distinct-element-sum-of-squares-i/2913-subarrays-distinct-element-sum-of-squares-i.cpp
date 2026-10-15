class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();
        int val;
        int sum=0;
        
        for(int i=0; i<n ; i++)
        {
            set<int> st;
            for(int j=i; j<n; j++)
            {
                st.insert(nums[j]);

                 val = st.size();
                 sum+=(val*val);

            }
            

        }
        return sum;
    }
};