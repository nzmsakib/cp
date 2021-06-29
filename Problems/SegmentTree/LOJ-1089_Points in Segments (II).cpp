/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE@RUET@BD
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

struct Node
{
    int x, y, n;
};

int leftSubTree(int node) { return node << 1; }
int rightSubTree(int node) { return (node << 1) + 1; }

const int mx = 50000;
Node tree[4 * mx], points[mx], segs[mx];

void build(int root, int left, int right)
{
    if (left == right)
    {
        tree[root] = points[left];
        tree[root].n = 0;
        return;
    }
    build(leftSubTree(root), left, (left + right) / 2);
    build(rightSubTree(root), (left + right) / 2 + 1, right);
    tree[root].x = tree[leftSubTree(root)].x;
    tree[root].y = tree[rightSubTree(root)].y;
    tree[root].n = 0;
}

void update(int root, int left, int right, int from, int to, int val = 0)
{
    if (tree[root].x > to || tree[root].y < from)
        return;
    // cout << tree[root].x << ' ' << tree[root].y << nl;
    // cout << from << ' ' << to << nl;

    if (tree[root].x >= from && tree[root].y <= to)
    { // Implement Here.
        tree[root].n++;
        return;
    }
    if (left == right)
        return;
    update(leftSubTree(root), left, (left + right) / 2, from, to);
    update(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
    return;
}
int query(int root, int left, int right, int p)
{
    if (tree[root].x > p || tree[root].y < p)
        return 0;
    if (left == right)
        return tree[root].n;
    return tree[root].n + query(leftSubTree(root), left, (left+right)/2, p) + query(rightSubTree(root), (left+right)/2+1, right, p);
}

void SolveTestCase(const int cno)
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> segs[i].x >> segs[i].y;
    }
    vi ara(q), b(q);
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
        ara[i] = b[i];
    }
    sort(ara.begin(), ara.end());
    for (int i=0; i<q; i++)
    {
        points[i].x = points[i].y = ara[i];
    }
    build(1, 0, q-1);
    for (int i=0; i<n; i++)
    {
        update(1, 0, q-1, segs[i].x, segs[i].y);
    }
    cout << "Case " << cno << ":\n";
    for (int i=0; i<q; i++)
    {
        cout << query(1, 0, q-1, b[i]) << nl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 10;
    if (t != 1)
        cin >> t;
    for (int i = 1; i <= t; i++)
        SolveTestCase(i);
}