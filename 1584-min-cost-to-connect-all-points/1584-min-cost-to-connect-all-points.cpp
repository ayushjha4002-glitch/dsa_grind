class Solution {
public:

    vector<int> parent;

    int find(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> edges;

        // Create all edges
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);

                edges.push_back({cost, i, j});
            }
        }

        // Sort by cost
        sort(edges.begin(), edges.end());

        int ans = 0;
        int count = 0;

        // Kruskal
        for(auto edge : edges) {

            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];

            int pu = find(u);
            int pv = find(v);

            if(pu != pv) {

                parent[pu] = pv;

                ans += cost;
                count++;

                if(count == n - 1)
                    break;
            }
        }

        return ans;
    }
};