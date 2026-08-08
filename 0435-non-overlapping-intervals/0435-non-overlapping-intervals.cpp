class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // Sort according to ending time
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;              // intervals to remove
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            
            // Overlap
            if (intervals[i][0] < prevEnd) {
                count++;
            }
            else {
                // No overlap, keep this interval
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};