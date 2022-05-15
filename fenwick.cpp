#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug.h"
#define debug(x...) {cerr << #x << ":\n", debug(x);}
#else
#define debug(x...)
#endif

typedef long long ll;
using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n, 0); 
    }

    FenwickTree(const vector<ll>& a) {
        n = (int)a.size();
        tree.assign(n, 0); 
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int i, ll delta) {
        while (i < n) {
            tree[i] += delta;
            i |= i + 1;
        }
    }

    ll sum(int l, int r) {
        return l == 0 ? sum(r) : sum(r) - sum(l - 1);
    }

private:
    vector<ll> tree; 
    int n;

private:
    ll sum(int i) {
        ll res = 0;
        while (i >= 0) {
            res += tree[i];
            i &= i + 1;
            --i;
        }
        return res;
    }
};

void solve(){
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

