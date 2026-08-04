class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                } else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int min=0;
        int x[]={-1,1,0,0};
        int y[]= {0,0,-1,1};
        while(!q.empty() && fresh>0){
            int size= q.size();
            while(size--){
            int r=q.front().first;
            int c= q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int rc= r+x[k];
                int cc= c+y[k];
                if(rc>=0 && rc<n && cc>=0 && cc<m && grid[rc][cc]==1){
                    grid[rc][cc]=2;
                    fresh--;
                    q.push({rc,cc});
                }
            }
            

            }
            min++;
            

        }
        if(fresh>0) return -1;
        return min;
    }
};