class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>s;
        for(int i=0; i< candyType.size();i++)
        {
            s.insert(candyType[i]);
        }
        return  min(candyType.size()/2 ,s.size());
        
    }
};