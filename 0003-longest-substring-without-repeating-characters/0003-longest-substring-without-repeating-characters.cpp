class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        vector<int>mp(256,-1);
        int l= 0;
         int r =0;
          int maxlen =0;
          while(r<n)
          {
            if(mp[s[r]]!=-1)
            {
                if(mp[s[r]]>=l)
                {
                     l= mp[s[r]]+1;
                }
            }
            int len =r-l+1;
            maxlen = max(maxlen,len);
            mp[s[r]]=r;
            r++;
          }
          return maxlen;
        
    }
};