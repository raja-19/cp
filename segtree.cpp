#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct MIN {
    ll defval = 1e17;
    ll operator()(ll a, ll b) {
        return min(a, b);
    }
};

struct SUM {
    ll defval = 0;
    ll operator()(ll a, ll b) {
        return a + b;
    }
};

template <typename T>
class SegmentTree {
public: 
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, op.defval);
    }
    SegmentTree(const vector<ll>& a) {
        n = (int)a.size();
        tree.assign(4 * a.size(), op.defval);
        init(a, 1, 0, n - 1); 
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r); 
    }

    void update(int i, ll val) {
        update(1, 0, n - 1, i, val);
    }

private:
    T op;
    int n;
    vector<ll> tree;

private:
    void init(const vector<ll>& a, int node, int segl, int segr) {
        if (segl == segr) {
            tree[node] = a[segl];
            return;
        }
        int segm = (segl + segr) / 2;
        init(a, 2 * node, segl, segm);
        init(a, 2 * node + 1, segm + 1, segr);
        tree[node] = op(tree[2 * node], tree[2 * node + 1]); 
    }

    ll get(int node, int segl, int segr, int l, int r) {
        if (l > r) return op.defval;
        if (segl == l && segr == r) return tree[node];
        int segm = (segl + segr) / 2;
        ll leftval = get(2 * node, segl, segm, l, min(segm, r)); 
        ll rightval = get(2 * node + 1, segm + 1, segr, max(l, segm + 1), r); 
        return op(leftval, rightval);
    }

    void update(int node, int segl, int segr, int i, int val) {
        if (segl == segr) {
            tree[node] = val;
            return;
        }
        int segm = (segl + segr) / 2;
        if (i <= segm) update(2 * node, segl, segm, i, val);
        else update(2 * node + 1, segm + 1, segr, i, val);
        tree[node] = op(tree[2 * node], tree[2 * node + 1]);
    }
};

void solve(){
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

