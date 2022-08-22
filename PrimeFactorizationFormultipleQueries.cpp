// // Practicing geeks for geeks 
// // Author: MD.Shahadat Hossain Bhuian
// // Codeforces userName : __Shahadat__
// // CodeChef userName : shahadat_43
// //---------------------------------------------

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
ll lcm(ll a,ll b) { return a/__gcd(a,b)*b; }
const ll Max = 100000;

vll spf(Max + 1);
void sieve() {
    loop(i, 1, Max, 1)spf[i] = i;
    loop(i, 4, Max, 2)spf[i] = 2;
    for (ll i = 3;i * i <= Max;i += 2) {
        if (spf[i] == i) {
            loop(j, i * i, Max, i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vll get_Factorization(ll n) {
    vll res;
    while (n != 1) {
        res.pb(spf[n]);
        n /= spf[n];
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vll p = get_Factorization(n);
    for (auto k : p)cout << k << " ";
    dp_x("");
}

int main()
{
    Faster;
    sieve();
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
