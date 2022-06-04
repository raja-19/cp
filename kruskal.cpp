#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug.h"
#define debug(x...) {cerr << #x << ":\n", debug(x);}
#else
#define debug(x...)
#endif

typedef long long ll;
using namespace std;

class DSU {
public:
    DSU(int n): parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    void unite(int i, int j) {
        i = find(i), j = find(j);
        if (i < j) swap(i, j);
        parent[j] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

private:
    vector<int> parent;
};

vector<vector<ll>> kruskal(int n, vector<vector<ll>>& edges) {
    vector<vector<ll>> res;
    sort(edges.begin(), edges.end(), [](vector<ll> e1, vector<ll> e2){return e1[2] < e2[2];});
    DSU dsu(n);
    for (vector<ll> e: edges) {
        ll u = e[0], v = e[1], w = e[2];
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            res.push_back({u, v, w});
        }
    }
    return res;
}

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

