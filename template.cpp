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


ll power(ll x, ll n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n % 2) return x * power(x, n - 1);
	ll t = power(x, n / 2);
	return t * t;
}

ll powerMod(ll x, ll n, ll m) {
	if (n == 0) return 1 % m;
	if (n == 1) return x % m;
	if (n % 2) return (x % m * power(x, n - 1) % m) % m;
	ll t = power(x, n / 2);
	return (t % m * t % m) % m;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll tc;
	cin >> tc;
	while (tc --) {

	}
	return 0;
}
