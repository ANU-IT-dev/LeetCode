class Solution {
public:
        vector<string> result;
        void solve(string &curr ,int n, int open ,int close)
        {
            if(curr.length()== 2*n)
            {
                result.push_back(curr);
                return;
            }

            if(open<n)
           {
            curr.push_back('(');
            solve(curr,n,open+1,close);// +1 is for count ki ek open bracket add ho chuka haii
            curr.pop_back();// backtrack
           }
        if(close<open)
        {
            curr.push_back(')');
            solve(curr,n,open, close+1);// +1 is for count ki ek close bracket add ho chuka hai
            curr.pop_back();// backtrack
        }
        }

        vector<string> generateParenthesis(int n) {
            string curr ="";
            int open =0;
            int close =0;

           solve(curr,n, open, close);

           return result;
        
    }
};