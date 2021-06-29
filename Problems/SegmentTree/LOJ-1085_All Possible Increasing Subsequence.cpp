/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE@RUET@BD
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_MAX 2000009 // 2e6+9
#define IMAX 1000000009   // 1e9+9
#define MD 1000000007
#define LSB(n) ((n) & (-n)) // Value of last significant bit that is on.

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
    Tuple() {}
    Tuple(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
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

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    ui n = v.size();
    for (ui i = 0; i < n; i++)
        in >> v[i];
    return in;
}
istream &operator>>(istream &in, vector<Tuple> &ara)
{
    ui n = ara.size();
    for (ui i = 0; i < n; i++)
    {
        // Custom input for a Tuple
        in >> ara[i].x >> ara[i].y;
    }
    return in;
}

template <class T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    ui n = v.size();
    if (n == 0)
        return out;
    out << v[0];
    for (ui i = 1; i < n; i++)
        out << ' ' << v[i];
    return out;
}
ostream &operator<<(ostream &out, const vector<Tuple> &ara)
{
    ui n = ara.size();
    if (n == 0)
        return out;
    for (ui i = 0; i < n; i++)
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

    void build(int root, int left, int right)
    {
        if (left == right)
        {
            st[root] = a[left];
            return;
        }
        build(leftSubTree(root), left, (left + right) / 2);
        build(rightSubTree(root), (left + right) / 2 + 1, right);
        st[root] = min(st[leftSubTree(root)], st[rightSubTree(root)]);
    }

    void update(int root, int left, int right, int from, int to, int val = 0)
    {
        if (from > right || to < left)
            return;
        if (left >= from && right <= to)
        { // Implement Here.
            // cout << val << nl;
            st[root] = val % MD;
            return;
        }
        update(leftSubTree(root), left, (left + right) / 2, from, to, val);
        update(rightSubTree(root), (left + right) / 2 + 1, right, from, to, val);
        st[root] = (st[leftSubTree(root)] + st[rightSubTree(root)]) % MD;
    }
    int query(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return 0;
        if (left >= from && right <= to)
        { // Implement Here.
            return st[root];
        }
        int qleft = query(leftSubTree(root), left, (left + right) / 2, from, to);
        int qright = query(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
        return (qleft + qright) % MD;
    }

public:
    SegmentTree(const int len)
    {
        n = len;
        st.assign(4 * n, 0);
    }
    SegmentTree(const vi &_a)
    {
        a = _a;
        n = (int)a.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int query(int i, int j)
    {
        return query(1, 0, n - 1, i, j);
    }
    void update(int i, int j, int val = 0)
    {
        // cout << val << nl;
        update(1, 0, n - 1, i, j, val);
        // cout << st << nl << nl;
    }
};

void SolveTestCase(const ui cno)
{
    cout << "Case " << cno << ':' << ' ';
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    vi b(a);
    sort(b.begin(), b.end());
    
    map<int, int> m;
    for (int i=0, j=0; i<n; i++)
    {
        if (m.count(b[i]) == 0)
            m[b[i]] = ++j;
    }

    SegmentTree tree(n);
    int res, ans;
    for (int i = 0; i < n; i++)
    {
        // cout << m[b[i]] << nl;
        res = tree.query(0, m[a[i]] - 1);
        tree.update(m[a[i]] - 1, m[a[i]] - 1, res + 1);
    }
    ans = tree.query(0, n - 1);
    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ui t = 10;
    if (t != 1)
        cin >> t;
    for (int i = 1; i <= t; i++)
        SolveTestCase(i);
}