class Solution {
public:
   typedef pair < int,string >p;
   struct comp{
    bool operator()(const p &a ,const p &b) const{
        if(a.first== b.first)
         return a.second< b.second;  // a:apple jiska priority kam hai// b: banana jiska priority lexicographical order mein
         //apple se jyada hai to isko top pe le jao so that ye pop ho jaye.

        return a.first>b.first;  // agar freq jyada hai mtlb priority kam hogi to top pe b jayga; and pop hoga.
    }
   };
   
    vector<string> topKFrequent(vector<string>& words, int k) {
       
        unordered_map< string , int> mp;
        for(auto word: words)
        {
            mp[word]++;
        }
        priority_queue <p, vector<p> ,comp> pq;
        for(auto &it:mp)
        {
            string value = it.first;
            int freq =  it.second;

            pq.push({freq, value});
            if( pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<string> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();

        }
        reverse( result.begin(),result.end());
        return result;
        
    }
};