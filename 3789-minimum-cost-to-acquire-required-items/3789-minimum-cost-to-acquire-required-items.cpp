class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans =0 ;
        long long minm = min( cost1+cost2, costBoth);
        int minNeed = min(need1,need2);
        ans = 1ll* minm* minNeed;
         need1= need1- minNeed;
         need2 = need2- minNeed;
        if(need1)
        {
            int min1 = min( cost1, costBoth);
            ans+= 1ll* min1*need1;

        }
        if(need2)
        {
             int min2 = min( cost2, costBoth);
             ans+= 1ll*min2* need2;
        }
       
        
       
        
        return ans;

        
    }
};