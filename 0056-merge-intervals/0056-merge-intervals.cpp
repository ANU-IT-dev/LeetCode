class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals according to starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Traverse all intervals
        for (auto &interval : intervals) {
            // If answer is empty OR no overlap
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            // Overlap exists
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};