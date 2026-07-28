class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> pos;
        int n= arr2.size();
        for(int i=0; i<n; i++)
        {
            pos[arr2[i]]=i;
        }
        sort(arr1.begin(), arr1.end(),[&](int a,int b){
            bool ina =pos.count(a);
        bool inb =pos.count(b);

        if(ina && inb)
        {
            return pos[a]<pos[b];
        }
        if(ina)
        return true;
        if(inb)
        return false;

        return a<b;

        

        });
        return arr1;
        
    }
};