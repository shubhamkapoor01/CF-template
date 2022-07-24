#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// to make unordered_map unhackable
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

#define MOD 1000000007
#define eb emplace_back
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

class SegmentTree {
private:
	vector<ll> tree;
	vector<ll> arr;

	void build(ll start, ll end, ll index) {
		if (start == end) {
			tree[index] = arr[start];
			return;
		}

		ll mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);

		// Change this
		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}

public:
	SegmentTree(vector<ll> v) {
		ll n = v.size();
		arr = v;
		ll s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s);
		fill(tree.begin(), tree.end(), 0);
		build(0, n - 1, 1);

		// for (auto &i: tree) {
		//     cout << i << ' ';
		// }
		
		return;
	}

	void update(ll start, ll end, ll index, ll query_index, ll val) {
		if (start == end) {
			arr[query_index] = val;
			tree[index] = val;
			return;
		}

		int mid = (start + end) / 2;

		if (mid >= query_index) {
			update(start, mid, 2 * index, query_index, val);
		} else {
			update(mid + 1, end, 2 * index + 1, query_index, val);
		}

		// Change this
		tree[index] = tree[2 * index] + tree[2 * index + 1];
	}

	ll query(ll start, ll end, ll index, ll left, ll right) {
		if (start > right || end < left) {
			return 0;
		}
		if (start >= left && end <= right) {
			return tree[index];
		}

		ll mid = (start + end) / 2;
		ll l = query(start, mid, 2 * index, left, right);
		ll r = query(mid + 1, end, 2 * index + 1, left, right);
		
		// Change this;
		ll merged = l + r;
		return merged;
	}

	vector<ll> getTree() {
		return tree;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, q;
	cin >> n >> q;
	vector<ll> v(n, 0);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}

	SegmentTree tree(v);

	while (q --) {
		ll type, x, y;
		cin >> type >> x >> y;

		if (type == 1) {
			tree.update(0, n - 1, 1, x - 1, y);
		} else {
			cout << tree.query(0, n - 1, 1, x - 1, y - 1) << endl;
		}
	}
	return 0;
}
