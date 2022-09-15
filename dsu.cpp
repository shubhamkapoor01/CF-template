// use it as unordered_map<int,int,custom_hash> mp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class DSU {
private:
    unordered_map<ll, ll, custom_hash> parent;
    unordered_map<ll, ll, custom_hash> rank;
    
public:
    void makeNode (ll node) {
        if (parent.find(node) != parent.end()) {
            return;
        } else {
            parent[node] = node;
            rank[node] = 1;
        }
    }
    
    ll findParent(ll node) {
    	if (parent.find(node) == parent.end()) {
    		makeNode(node);
    	}
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
