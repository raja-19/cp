#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct GCD {
    ll operator()(ll a, ll b) {
        return __gcd(a, b);
    }
};

template <typename T>
class SparseTable {
public:
    int n, k;
    T op;
    vector<vector<ll>> m;
    SparseTable(const vector<ll>& a) {
        n = (int)a.size();
        k = 32 - __builtin_clz(n);
        m.assign(n, vector<ll>(k, 0));

        for (int i = 0; i < n; i++) m[i][0] = a[i];
        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                m[i][j] = op(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll get(int i, int j) {
        int l = 31 - __builtin_clz(j - i + 1); 
        return op(m[i][l], m[j - (1 << l) + 1][l]);
    }
};
