class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
           map<int,int>freq;
           for(int x:nums)
           {
            if(x%2==0)
               freq[x]++;
           }
           int ans =-1;
           int maxfreq=0;
           for(auto &it: freq)
           {
            int num= it.first;
            int count = it.second;
            if(count > maxfreq)
            {
                maxfreq= count;
                ans = num;

            }
            else if (count == maxfreq && num < ans) {
                ans = num;
            }

           }
           return ans;
        


        
    }
};