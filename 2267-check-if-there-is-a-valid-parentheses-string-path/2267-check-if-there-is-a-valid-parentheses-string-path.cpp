class Solution {
public:
    int m, n;
    int t[101][101][201];

    bool solve(int i, int j, int opencount, vector<vector<char>>& grid) {
        
        opencount += (grid[i][j] == '(' ? 1 : -1);

        if (opencount < 0) {
            return false;
        }

        if (t[i][j][opencount] != -1) {
            return t[i][j][opencount];
        }

        if (i == m - 1 && j == n - 1) {
            return t[i][j][opencount] = (opencount == 0);
        }

        if (i + 1 < m) {
            if (solve(i + 1, j, opencount, grid)) {
                return t[i][j][opencount] = true;
            }
        }

        if (j + 1 < n) {
            if (solve(i, j + 1, opencount, grid)) {
                return t[i][j][opencount] = true;
            }
        }

        return t[i][j][opencount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, grid);
    }
};