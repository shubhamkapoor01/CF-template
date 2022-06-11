class DSU {
private:
    unordered_map<ll, ll> parent;
    unordered_map<ll, ll> rank;
    
public:
    DSU (ll node) {
        if (parent.find(node) != parent.end()) {
            return;
        } else {
            parent[node] = node;
            rank[node] = 1;
        }
    }
    
    ll findParent(ll node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(ll a, ll b) {
        ll A = findParent(a);
        ll B = findParent(b);
        
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
