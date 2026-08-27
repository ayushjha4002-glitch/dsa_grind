class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {

            vector<int> edge = edges[i];

            int src = edge[0];
            int dst = edge[1];
            double wt = succProb[i];

            adj[src].push_back({dst, wt});
            adj[dst].push_back({src, wt});
        }

        priority_queue<pair<double,int>> pq;

        vector<double> res(n, 0);

        res[start_node] = 1;

        pq.push({1, start_node});

        while(!pq.empty()) {

            double pr = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(node == end_node) {
                return pr;
            }

            for(int j = 0; j < adj[node].size(); j++) {

                int neigh = adj[node][j].first;
                double edgeProb = adj[node][j].second;

                double npr = pr * edgeProb;

                if(npr > res[neigh]) {

                    res[neigh] = npr;

                    pq.push({npr, neigh});
                }
            }
        }

        return 0.0;
    }
};