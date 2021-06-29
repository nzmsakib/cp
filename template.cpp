/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE-18@RUET@BD
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_MAX 2000009   // 2e6+9
#define IMAX 1000000009     // 1e9+9
#define LSB(n) ((n) & (-n)) // Value of last significant bit that is on.

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef bitset<ARRAY_MAX> bools;

#define nl '\n'
#define ALL(v) v.begin(), v.end()
#define UNIQ(v) v.resize(unique(ALL(v)) - v.begin())

bool ispow2(const ll val)
{
    return (val & (val - 1)) == 0;
}

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        in >> v[i];
    return in;
}

template <class T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    int n = v.size();
    if (n == 0)
        return out;
    out << v[0];
    for (int i = 1; i < n; i++)
        out << ' ' << v[i];
    return out;
}


void SolveTestCase(const int cno)
{
    cout << (5 & 1) << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    if (t != 1)
        cin >> t;
    for (int i = 1; i <= t; i++)
        SolveTestCase(i);
}