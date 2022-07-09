#include<bits/stdc++.h>
using namespace std;
    
class Kosaraju {
    void dfs(vector<vector<int>>& graph, int root, vector<int>& vis, stack<int>& st) {
        vis[root] = true;
        for (auto neighbor: graph[root]) {
            if (!vis[neighbor]) {
                dfs(graph, neighbor, vis, st);
            }
        }
        st.push(root);
    }
    
    void rdfs(vector<vector<int>>& graph, int root, vector<int>& vis, stack<int>& st, vector<int>& curr) {
        vis[root] = true;
        curr.push_back(root);
        for (auto neighbor: graph[root]) {
            if (!vis[neighbor]) {
                rdfs(graph, neighbor, vis, st, curr);
            }
        }
    }
    
public:
    vector<vector<int>> kosaraju(vector<vector<int>>& graph, int n) {
        stack<int> st;
        vector<int> vis(n);
        for (int i = 0; i < n; i ++) {
            if (!vis[i]) {
                dfs(graph, i, vis, st);
            }
        }
        vector<vector<int>> rgraph(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < graph[i].size(); j ++) {
                rgraph[graph[i][j]].push_back(i);
            }
            vis[i] = false;
        }
        vector<vector<int>> scc;
        while (!st.empty()) {
            if (vis[st.top()]) {
                st.pop();
                continue;
            }
            vector<int> curr;
            rdfs(rgraph, st.top(), vis, st, curr);
            scc.push_back(curr);
            st.pop();
        }
        // for (auto i: scc) {
        //     for (auto j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return scc;
    }
};
    
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i ++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    Kosaraju kosaraju;
    vector<vector<int>> scc = kosaraju.kosaraju(graph, n);
    cout << scc.size() << endl;
    return 0;
}
