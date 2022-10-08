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
#define loop(i, Start, End, Inc) for (ll i = Start; i <= End; i += Inc)
#define loopR(i, Start, End, Dec) for (ll i = Start; i >= End; i -= Dec)

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
#define REP(i, n) for (ll i = 0; i < n; i++)
const ll M = 101;
ll ar[M][M], I[M][M];

void mul(ll A[][M], ll B[][M], ll dim)
{
    ll res[dim + 1][dim + 1];
    REP(i, dim)
    {
        REP(j, dim)
        {
            res[i][j] = 0;
            REP(k, dim)
            {
                ll x = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    REP(i, dim)
    REP(j, dim)
    A[i][j] = res[i][j];
}

void power(ll A[][M], ll dim, ll n)
{
    REP(i, dim)
    REP(j, dim)
    {
        if (i == j)
            I[i][j] = 1;
        else
            I[i][j] = 0;
    }
    while (n)
    {
        if (n & 1)
            mul(I, A, dim), n--;
        else
            mul(A, A, dim), n >>= 1;
    }
    REP(i, dim)
    REP(j, dim)
    A[i][j] = I[i][j];
}

void print(ll A[][M], ll dim)
{
    REP(i, dim)
    {
        REP(j, dim)
        cout << A[i][j] << ' ';
        nl;
    }
}

void solve()
{
    ll dim, n;
    cin >> dim >> n;
    REP(i, dim)
    {
        REP(j, dim)
        cin >> ar[i][j];
    }
    power(ar, dim, n);
    print(ar, dim);
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
