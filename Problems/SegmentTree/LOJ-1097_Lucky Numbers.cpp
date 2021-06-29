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

class SegTree
{
private:
    int n;
    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }
    vi tree;
public:
    SegTree(const int a)
    {
        n = a;
        tree.assign(4*n, 0);
        build(1, 1, n-1);
    }
    void build(int root, int left, int right)
    {
        if (left == right)
        {
            tree[root] = left & 1;
            return;
        }
        build(leftSubTree(root), left, (left + right) / 2);
        build(rightSubTree(root), (left + right) / 2 + 1, right);
        tree[root] = tree[leftSubTree(root)] + tree[rightSubTree(root)];
    }

    void update(int root, int left, int right, int pos)
    {
        if (left == right)
        {
            tree[root] = 0;
            return;
        }
        if (tree[leftSubTree(root)] >= pos)
            update(leftSubTree(root), left, (left+right)/2, pos);
        else
            update(rightSubTree(root), (left+right)/2+1, right, pos-tree[leftSubTree(root)]);
        tree[root] = tree[leftSubTree(root)] + tree[rightSubTree(root)];
    }
    int query(int root, int left, int right, int pos)
    {
        if (left == right)
            return left;
        if (tree[leftSubTree(root)] >= pos)
            return query(leftSubTree(root), left, (left+right)/2, pos);
        else
            return query(rightSubTree(root), (left+right)/2+1, right, pos-tree[leftSubTree(root)]);
    }
} tree(1429500);

int ans[100005];

void SolveTestCase(const int cno)
{
    int n;
    cin >> n;
    cout << "Case " << cno << ": " << ans[n] << nl;
}

void Init()
{
    ans[1] = 1;
    for (int i=2; i<100001; i++)
    {
        int el = tree.query(1, 1, 1429499, i);
        ans[i] = el;
        int j = (1429500 / el) * el;
        for ( ; j >= el; j -= el)
            tree.update(1, 1, 1429499, j);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Init();

    int t = 10;
    if (t != 1)
        cin >> t;
    for (int i = 1; i <= t; i++)
        SolveTestCase(i);
}