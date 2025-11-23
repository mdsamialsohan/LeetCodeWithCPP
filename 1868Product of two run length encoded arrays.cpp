class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i =0, j=0;
        vector<vector<int>>ans;
        while(i<encoded1.size() && j<encoded2.size())
        {
            int mult = encoded1[i][0] * encoded2[j][0];
            int minFreq = min(encoded1[i][1],encoded2[j][1]);

            if(!ans.empty() && ans.back()[0]==mult)
            {
                ans.back()[1]+=minFreq;
            }
            else{
                ans.push_back({mult,minFreq});
            }
            encoded1[i][1]-=minFreq;
            encoded2[j][1]-=minFreq;
            if(encoded1[i][1]==0) i++;
            if(encoded2[j][1]==0) j++;
        }
        return ans;
    }
};