class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up =0, col=matrix[0].size(), row=matrix.size(), left = 0;
        int right = col-1, down = row-1;
        
        vector<int>ans;

        while(ans.size()<col*row)
        {
            for(int c = left; c<=right;c++)
                ans.push_back(matrix[up][c]);
            
            for(int r=up+1; r<=down;r++)
                ans.push_back(matrix[r][right]);
            if(up!=down)
                for(int c=right-1;c>=left;c--)
                    ans.push_back(matrix[down][c]);
            if(right!=left)
                for(int r=down-1;r>up;r--)
                    ans.push_back(matrix[r][left]);
            up++;
            down--;
            right--;
            left++;
        }
        return ans;

    }
};