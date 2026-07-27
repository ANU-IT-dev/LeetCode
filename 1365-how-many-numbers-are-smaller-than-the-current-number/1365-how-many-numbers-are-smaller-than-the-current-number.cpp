class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp;
        
        int n= nums.size();
        int j=1;
        for(int i=0; i<n; i++)
        {
            //[8,3,2,2,1]
            
            int count =0;
            int j=0;
            while(j<n)
            {
                
                if(nums[i]>nums[j])
                count++;
                j++;
            }
            temp.push_back(count);

            
        }
        return temp;
        
    }
};