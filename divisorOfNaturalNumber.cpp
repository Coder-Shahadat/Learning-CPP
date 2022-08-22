// Practicing Geeks for Geeks
// Author: MD.Shahadat Hossain Bhuian
// Codeforces userName : __Shahadat__
// CodeChef userName : shahadat_43
//---------------------------------------------

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vstr;
typedef vector<pll> vpl;
typedef set<ll> sll;
#define all(v) v.begin(),v.end()
#define loop(i,Start,End,Inc) for(ll i=Start;i<=End;i+=Inc)
#define loopR(i,Start,End,Dec) for(ll i=Start;i>=End;i-=Dec)
#define dp_x(x) cout<<x<<endl
#define dp_xy(x,y) cout<<x<<" "<<y<<endl
#define endl "\n"
#define pb push_back
#define asc(v) sort(v.begin(),v.end())
#define dsc(v) sort(v.begin(),v.end()),reverse(v.begin(),v.end())
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL);
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void solve() {
    ll n;
    cin >> n;
    vll v;
    loop(i, 1, sqrt(n), 1) {
        if (n % i == 0) {
            if (n / i == i)v.pb(i);
            else v.pb(i), v.pb(n / i);
        }
    }
    asc(v);
    for (auto k : v)cout << k << " ";
    dp_x("");
}

int main()
{
    Faster;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
