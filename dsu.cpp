class DSU {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
public:
    DSU (int node) {
        if (parent.find(node) != parent.end()) {
            return;
        } else {
            parent[node] = node;
            rank[node] = 1;
        }
    }
    
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int a, int b) {
        int A = findParent(a);
        int B = findParent(b);
        
        if (A == B) {
            return;
        }
        
        if (rank[A] < rank[B]) {
            swap(A, B);
        }
        
        parent[B] = A;
        
        if (rank[A] == rank[B]) {
            rank[A] ++;
        }
    }
};
