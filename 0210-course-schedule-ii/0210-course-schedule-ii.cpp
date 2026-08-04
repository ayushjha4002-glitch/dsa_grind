class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inde(numCourses,0);
        vector<int>res;
        for(int i=0;i<prerequisites.size();i++){
            int src=prerequisites[i][0];
            int dest=prerequisites[i][1];
            adj[dest].push_back(src);
            inde[src]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inde[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            res.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                int neigh=adj[node][j];
                inde[neigh]--;
                if(inde[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(res.size()!=numCourses) return {};
        return res;
        
    }
};