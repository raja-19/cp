#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> sieve(ll n) {
    vector<ll> isprime(n + 1, 1);
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (isprime[i]) {
           for (ll j = 2 * i; j <= n; j += i) isprime[j] = 0; 
        }
    } 
    vector<ll> primes;
    for (ll i = 0; i < n; i++) {
        if (isprime[i]) primes.push_back(i);
    }
    return primes;
}

void solve(){
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

