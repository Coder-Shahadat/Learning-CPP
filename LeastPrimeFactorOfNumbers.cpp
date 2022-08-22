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

void solve() {
    ll n;
    cin >> n;
    vll least_prime(n + 1, 0);
    least_prime[1] = 0;
    loop(i, 2, n, 1) {
        if (least_prime[i] == 0) {
            least_prime[i] = i;
            loop(j, i * i, n, i) {
                if (least_prime[j] == 0) {
                    least_prime[j] = i;
                }
            }
        }
    }
    loop(i, 1, n, 1)cout << least_prime[i] << " ";
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
