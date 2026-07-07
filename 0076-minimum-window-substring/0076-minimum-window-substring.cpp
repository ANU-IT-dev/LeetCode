class Solution {
public:
    string minWindow(string s, string t) {
        int m= t.length();
        int n =s.length();
        int l= 0;
        int r =0;
        int minlength = INT_MAX;
         int sindex=-1;
         int count =0;
        int hash[256] ={0};
        for( int i=0; i<m;i++)
        {
            hash[t[i]]++;
        }
        while(r<n)
        {
            if(hash[s[r]]>0)
            {
                count++;
            }
            hash[s[r]]--;
            while(count==m)
            {
            if(r-l+1< minlength)
            {
                minlength = r-l+1;
                sindex=l;

            }
            hash[s[l]]++;
            if(hash[s[l]]>0) 
            {
                count--;
            }
            l++;
           
            }
            r++;
        }
        return (sindex==-1?"": (s.substr(sindex,minlength)));
        
        
        
    }
};