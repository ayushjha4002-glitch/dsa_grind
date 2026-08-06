class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int sr=times[i][0];
            int des= times[i][1];
            int wt= times[i][2];
            adj[sr-1].push_back({des-1,wt});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int d= p.first;
            int node= p.second;
            if(d>dist[node]) continue;
            for(int j=0;j<adj[node].size();j++){
                int neigh= adj[node][j].first;
                int wt=adj[node][j].second;
                if(d+wt<dist[neigh]){
                    dist[neigh]=d+wt;
                    pq.push({d+wt,neigh});
                }
            }
        }
        int res=0;
        for(auto i:dist){
            if(i==INT_MAX) return -1;
            res=max(res,i);
        }
        return res;
    }
};