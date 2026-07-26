class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        int n=arr.size();
        int i=0, j=1;
        int mindiff = arr[j]-arr[i];
        result.push_back({arr[i],arr[j]});
        i++;
        j++;

        while(j<n)
        {
            int diff =arr[j]-arr[i];
            if(diff<mindiff)
            {
                mindiff= diff;
                result.clear();
                result.push_back({arr[i],arr[j]});
            }
            else if( diff== mindiff)
            {
                result.push_back({arr[i],arr[j]});
            }
            i++;
            j++;
        }
        return result;
        
    }
};