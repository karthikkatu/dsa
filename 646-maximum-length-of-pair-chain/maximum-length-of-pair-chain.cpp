class Solution {
public:
    static bool compare(const vector<int> &p1,const vector<int> &p2){
        return p1[1] < p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n==0){
            return 0;
        }

        sort(pairs.begin(), pairs.end(), compare);

        int Maxleng = 1;
        int currEnd = pairs[0][1];
        for(int i=1;i<n;i++){
            if(pairs[i][0] > currEnd){
                Maxleng++;
                currEnd = pairs[i][1];
            }
        }
        
        return Maxleng;
    }
};