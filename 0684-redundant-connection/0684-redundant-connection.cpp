class Solution {
public:
    vector<int> parent;

    int find(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);

        // Initialize parent
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        // Process edges
        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];

            int pu = find(u);
            int pv = find(v);

            if(pu == pv){
                return {u, v};
            }

            parent[pu] = pv;
        }

        return {};
    }
};