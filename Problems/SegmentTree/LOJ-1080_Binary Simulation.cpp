/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE@RUET@BD
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_MAX 2000009 // 2e6+9
#define INT_MAX 1000000009 // 1e9+9

typedef unsigned int ui;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef bitset<ARRAY_MAX> bools;

struct Tuple
{
    int x, y;
    
    bool operator<(const Tuple &tuple) const
    {
        // Custom sorting function definition goes here.
        return (x < tuple.x) || (!(tuple.x < x) && y < tuple.y);
    }
};
typedef vector<Tuple> vt;

#define nl '\n'
#define ALL(v) v.begin(), v.end()
#define UNIQ(v) v.resize(unique(ALL(v)) - v.begin())

bool ispow2(const ll val)
{
    return (val & (val - 1)) == 0;
}

template<class T>
istream &operator>>(istream &in, vector<T> &v)
{
    ui n = v.size();
    for (ui i=0; i<n; i++)
        in >> v[i];
    return in;
}
istream &operator>>(istream &in, vector<Tuple> &ara)
{
    ui n = ara.size();
    for (ui i=0; i<n; i++)
    {
        // Custom input for a Tuple
        in >> ara[i].x >> ara[i].y;
    }
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    ui n = v.size();
    if (n == 0)
        return out;
    out << v[0];
    for (ui i=1; i<n; i++)
        out << ' ' << v[i];
    return out;
}
ostream &operator<<(ostream &out, const vector<Tuple> &ara)
{
    ui n = ara.size();
    if (n == 0)
        return out;
    for (ui i=0; i<n; i++)
    {
        // Custom output for a Tuple
        cout << ara[i].x << ' ' << ara[i].y << nl;
    }
    return out;
}

class SegmentTree
{
private:
    int n;
    vi st, a;

    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }

    void updateTree(int root, int left, int right, int from, int to, int val = 0)
    {
        if (from > right || to < left)
            return;
        if (left >= from && right <= to)
        {
            st[root]++;
            return;
        }
        if (left != right)
        {
            updateTree(leftSubTree(root), left, (left + right) / 2, from, to);
            updateTree(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
            return;
        }
    }
    int queryTree(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return 0;
        if (left >= from && right <= to)
        {
            return st[root];
        }
        if (left != right)
        {
           return st[root] + queryTree(leftSubTree(root), left, (left + right) / 2, from, to) +
            queryTree(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
        }
    }

public:
    SegmentTree(const vi &_a)
    {
        a = _a;
        n = (int)a.size();
        st.assign(4 * n, 0);
        //cout << st << nl;
    }
    int queryTree(int i)
    {
        int res = queryTree(1, 0, n-1, i, i);
        //cout << "Flips: " << res << nl;
        return (res % 2 ? !a[i] : a[i]);
    }
    void updateTree(int i, int j)
    {
        updateTree(1, 0, n-1, i, j);
        //cout << st << nl;
    }
};









void SolveTestCase(const ui cno)
{
    cout << "Case " << cno << ':' << nl;
    string s;
    cin >> s;
    int l = s.size();
    vi a(l);
    for (int i=0; i<l; i++)
        a[i] = s[i] - '0';
    SegmentTree tree(a);
    int q;
    cin >> q;
    int i, j;
    char c;
    while (q--)
    {
        cin >> c;
        if (c == 'I')
        {
            cin >> i >> j;
            tree.updateTree(i-1, j-1);
        }
        else
        {
            cin >> i;
            cout << tree.queryTree(i-1) << nl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ui t = 10;
    if (t != 1)
        cin >> t;
    for (int i=1; i<=t; i++)
        SolveTestCase(i);
}