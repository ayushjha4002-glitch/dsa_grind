class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); i++){

            vector<int> flight = flights[i];

            int source = flight[0];
            int dest = flight[1];
            int wt = flight[2];

            adj[source].push_back({dest, wt});
        }

        vector<int> res(n, 1e8);
        res[src] = 0;

        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0;

        while(!q.empty() && stops <= k){

            int sz = q.size();

            vector<int> temp = res;

            while(sz--){

                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                for(int j = 0; j < adj[node].size(); j++){

                    int neigh = adj[node][j].first;
                    int wt = adj[node][j].second;

                    if(cost + wt < temp[neigh]){

                        temp[neigh] = cost + wt;

                        q.push({neigh, temp[neigh]});
                    }
                }
            }

            res = temp;
            stops++;
        }

        if(res[dst] == 1e8)
            return -1;

        return res[dst];
    }
};