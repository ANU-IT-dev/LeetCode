class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        // frequency count;
        for(char &ch :tasks)
        {
            mp[ch-'A']++;
        }
        int time=0;
        priority_queue<int> pq;// max heap to store only frequencies
        // heap
        for(int i=0; i<26; i++)
        {
            if(mp[i]>0)
            {
                pq.push(mp[i]);
            }
            
        }
        while(!pq.empty())
        {
            int cycle =n+1;
            vector<int>temp;
           
                while(cycle>0 && !pq.empty())
                {
                    int freq= pq.top();
                    pq.pop();
                    freq--;
                    if(freq>0)
                    {
                         temp.push_back(freq);
                    }
                   
                   
                    cycle--;
                     time++;
                }
        for(auto x: temp)
          {
            pq.push(x);
          }
          if(pq.empty())
             break;

             time+=cycle;
          

      }
            
        return time;
    }
};