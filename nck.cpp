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

class NCK {
public:
   vector<ll> f; 

   NCK(ll n): f(n + 1) {
       f[0] = 1;
       for (ll i = 1; i <= n; i++) {
           f[i] = (f[i - 1] * i) % MOD;
       }
  }
   ll operator()(ll n, ll k) {
       if (k < 0 || n < k) return 0;
       return ((f[n] * minv(f[n - k]) % MOD) * minv(f[k])) % MOD; 
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
