class Solution {
private:
    int timer;
    
    void dfs(vector<vector<int>>& graph, int root, int parent, vector<bool>& vis, 
            vector<vector<int>>& bridges, vector<int>& tin, vector<int>& low) {
        
        vis[root] = true;
        tin[root] = timer;
        low[root] = timer;
        timer ++;
        
        for (auto neighbour: graph[root]) {
            if (parent == neighbour) {
                continue;
            }
            
            if (vis[neighbour]) {
                low[root] = min(low[root], low[neighbour]);
                
            } else {
                dfs(graph, neighbour, root, vis, bridges, tin, low);
                low[root] = min(low[root], low[neighbour]);
                
                if (low[neighbour] > tin[root]) {
                    bridges.push_back({root, neighbour});
                }
            }
        }
        
        return;
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < m; i ++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>> bridges;
        vector<bool> vis(n, false);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        timer = 0;
        
        for (int i = 0; i < n; i ++) {
            if (!vis[i]) {
                dfs(graph, i, -1, vis, bridges, tin, low);
            }
        }
        
        return bridges;
    }
};
