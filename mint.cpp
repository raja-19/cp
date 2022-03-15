#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

ll mpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll minv(ll a) {
    return mpow(a, MOD - 2);
}

class mint {
public:
    ll val;
    mint() = default;
    mint(ll x): val(x) {}
    mint (const mint& other) {
        val = other.val;
    }
    const mint& operator=(const mint& other) {
        val = other.val;
        return *this;
    }
    mint operator++() {
        mint tmp = *this;
        val = (val + 1) % MOD;
        return tmp;
    }
    const mint& operator++(int) {
        val = (val + 1) % MOD;
        return *this;
    }
    mint operator--() {
        mint tmp = *this;
        val = (val - 1 + MOD) % MOD;
        return tmp;
    }
    const mint& operator--(int) {
        val = (val - 1 + MOD) % MOD;
        return *this;
    }
    const mint& operator+=(const mint& other) {
        val = (val + other.val) % MOD;
        return *this;
    }
    const mint& operator-=(const mint& other) {
        val = (val - other.val + MOD) % MOD;
        return *this;
    }
    const mint& operator*=(const mint& other) {
        val = (val * other.val) % MOD;
        return *this;
    }
    const mint& operator/=(const mint& other) {
        val = (val * minv(other.val)) % MOD;
        return *this;
    }
};

mint operator+(const mint& a, const mint& b) {
    return (a.val + b.val) % MOD;
}
mint operator-(const mint& a, const mint& b) {
    return (a.val - b.val + MOD) % MOD;
}
mint operator*(const mint& a, const mint& b) {
    return (a.val * b.val) % MOD;
}
mint operator/(const mint& a, const mint& b) {
    return (a.val * minv(b.val)) % MOD;
}
mint mpow(const mint& a, const mint& b) {
    return mpow(a.val, b.val);
}
mint minv(const mint& a) {
    return minv(a.val);
}
istream& operator>>(istream& is, mint& a) {
    is >> a.val;
    return is;
}
ostream& operator<<(ostream& os, const mint& a) {
    os << a.val;
    return os;
}

void solve(){
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

