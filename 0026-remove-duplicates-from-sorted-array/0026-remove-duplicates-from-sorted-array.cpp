class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()==0) return 0;
        int i=0; // for the unique elememts
        for(int j=0; j<nums.size();j++)
        {
            if(nums[i]!= nums[j])
            {
                i++;
                nums[i]= nums[j];

            }

        }
        return i+1; // here i represents index.
        
       /*
        if(nums.size()==0) return 0;
        set<int>s(nums.begin(),nums.end());
        int i=0;
        for(int x:s)
        {
            nums[i] =x;
            i++;

        }
        return i; // here i represents count
        */
        
     }
     
};