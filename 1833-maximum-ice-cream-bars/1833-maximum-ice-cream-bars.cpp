class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        int n= costs.size();
        int count=0;
        for(int i=0; i<n; i++) //1,1,2,3,4
        {
            if(coins>=costs[i])
            {
                count++;
                coins-=costs[i];
            }
            else break;

        }
        return count;
    }
};