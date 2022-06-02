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
