class Solution {
public:
   typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1
        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }
        // step 2

        priority_queue<p,vector<p>,greater<p>> pq; //min heap;

         // step3. push elements into min heap;
        // maintains size of k;

        for(auto & it:mp)
        {
            int value =it.first;
            int freq = it.second;
        
        pq.push({freq,value});

        if(pq.size()>k)
        {
            pq.pop();
        }
        }

        vector<int> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();

        }
        return result;




    }
};