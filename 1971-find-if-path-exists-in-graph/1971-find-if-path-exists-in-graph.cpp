class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node]=true;
    for(int i=0;i<adj[node].size();i++){
        int neigh= adj[node][i];
        if(vis[neigh]!=true){
            dfs(neigh,adj,vis);
        }
    }
    return;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i< edges.size();i++){
            vector<int>edge=edges[i];
            int src= edge[0];
            int dest= edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<bool>vis(n,0);
        dfs(source,adj,vis);
        return vis[destination];
        
    }
};