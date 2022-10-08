// Author: MD.Shahadat Hossain Bhuian
// Codeforces userName : __Shahadat__
// CodeChef userName : shahadat_43
//---------------------------------------------

// Libary
#include <bits/stdc++.h>
using namespace std;

// Type definition
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vstr;
typedef vector<pll> vpl;
typedef set<ll> sll;

// Loop
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rev(i, n) for (ll i = n - 1; i >= 0; i--)

// Printing statement
#define dp_x(x) cout << x << endl
#define dp_xy(x, y) cout << x << " " << y << endl
#define nl cout << "\n"
#define printArray(v) \
    for (auto k : v)  \
    cout << k << " "
#define yes dp_x("Yes")
#define no dp_x("No")

// STL operation
#define pb push_back
#define in insert
#define all(v) v.begin(), v.end()
#define asc(v) sort(all(v))
#define dsc(v) asc(v), reverse(all(v))
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// Precalculation
const ll mod = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

ll lenN(ll n)
{
    ll res = 0;
    while (n != 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

ll binExp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Solution Start Here
vector<vll> mul(vector<vll> a, vector<vll> b)
{
    ll sz = a.size();
    vector<vll> res(sz, vll(sz, 0));
    rep(i, sz)
    {
        rep(j, sz)
        {
            rep(k, sz)
            {
                ll x = (a[i][k] * b[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    return res;
}

vector<vll> power(vector<vll> v, ll dim, ll n)
{
    vector<vll> I(dim, vll(dim, 0));
    rep(i, dim) I[i][i] = 1;
    while (n)
    {
        if (n & 1)
            I = mul(I, v), n--;
        else
            v = mul(v, v), n >>= 1;
    }
    return I;
}

void print(vector<vll> &v)
{
    ll sz = v.size();
    rep(i, sz)
    {
        rep(j, sz)
        {
            cout << v[i][j] << ' ';
        }
        nl;
    }
}

void solve()
{
    ll dim, n;
    cin >> dim >> n;
    vector<vll> v(dim, vll(dim, 0));
    rep(i, dim)
    {
        rep(j, dim)
        {
            cin >> v[i][j];
        }
    }
    vector<vll> ans = power(v, dim, n);
    print(ans);
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
