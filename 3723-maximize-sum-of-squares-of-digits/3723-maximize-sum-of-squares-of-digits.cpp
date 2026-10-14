class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if((sum > num*9))
        {
            return "";
        }
        string ans ="";
        while(num--)
        {
            int digit = min(9, sum);
            ans+= to_string(digit);
            sum-= digit;
            

        }
        
        return ans;

    }
    };