#include <bits/stdc++.h>
#include <climits>

#ifdef DEBUG
#include "debug.h"
#define debug(x...) {cerr << #x << ":\n", debug(x);}
#else
#define debug(x...)
#endif

typedef long long ll;
using namespace std;

const int INF = 1e9 + 5;
const ll INFLL = 1e17 + 5; 

class BinaryLift {
public:
    BinaryLift(vector<vector<int>>& adj, int root) {
        int n = (int)adj.size();
        up.assign(n, vector<int>(31, -1));
        depth.assign(n, 0);
        dfs(root, -1, adj);
    }

    int lift(int u, int k) {
        int res = u;
        for (int i = 30; i >= 0; i--) {
            if (res == -1) break;
            if ((k >> i) & 1) {
                res = up[res][i]; 
            }
        }
        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int i = 30; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        } 
        return up[u][0];
    }

private:
    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int u, int p, vector<vector<int>>& adj) {
        if (p >= 0) depth[u] = depth[p] + 1;
        up[u][0] = p;
        for (int i = 1; i <= 30; i++) {
            if (up[u][i - 1] == -1) break;
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v: adj[u]) {
            if (v != p) dfs(v, u, adj);
        }
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

