class Solution {
public:
void dfs(vector<vector<int>>& image, int i, int j,int oldcolor, int newcolor){
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size()) return;
    if(image[i][j]!=oldcolor) return;
    image[i][j]=newcolor;
    dfs(image,i+1,j,oldcolor,newcolor);
    dfs(image,i-1,j,oldcolor,newcolor);
    dfs(image,i ,j+1,oldcolor,newcolor);
    dfs(image,i,j-1,oldcolor,newcolor);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor= image[sr][sc];
        if(oldcolor==color) return image;
        dfs(image,sr,sc,oldcolor,color);
        return image;
        
    }
};