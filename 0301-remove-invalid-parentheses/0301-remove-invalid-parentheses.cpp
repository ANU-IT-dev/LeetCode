class Solution {
public:
    set<string> ans;

    bool valid(string s) {
        int cnt = 0;

        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')') {
                cnt--;
                if (cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    void solve(string s, int start, int rem) {
        if (rem == 0) {
            if (valid(s))
                ans.insert(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1])
                continue;

            if (s[i] == '(' || s[i] == ')') {
                string t = s.substr(0, i) + s.substr(i + 1);
                solve(t, i, rem - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left + right);

        return vector<string>(ans.begin(), ans.end());
    }
};