class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n= seats.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            // [1,3,5]
            // [2,4,7]
            int diff= abs(seats[i]-students[i]);
             sum= sum+diff;
        }
        return sum;
        
    }
};