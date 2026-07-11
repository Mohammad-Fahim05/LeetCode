class Solution {
public:

        void dfs(int node , vector<int> &visited, vector<vector<int>> &adj,
        vector<int> &component){
            visited[node] = 1;
            component.push_back(node);
            for(auto neighbor : adj[node]){
                if(!visited[neighbor]) dfs(neighbor, visited, adj,component);
            }
        }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges ){
            int u = edge[0];
            int v=  edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<int> visited(n,0);
        for(int i = 0; i< n;i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, visited, adj,component);
                int size = component.size();
                int edgeCount = 0;

                for(auto node : component) edgeCount += adj[node].size();
                edgeCount /= 2;

                if(edgeCount == (size * (size-1)/2)) count++;
            } 
        }
        return count;
    }
};