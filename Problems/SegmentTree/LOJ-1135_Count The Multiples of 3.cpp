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

class SegTree
{
private:
    int n;
    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }
    vi tree, data;

public:
    SegTree(const vi &a)
    {
        n = a.size();
        data.assign(a.begin(), a.end());
        tree.assign(4 * n, 0);
        build(1, 0, n-1);
    }
    void build(int root, int left, int right)
    {
        if (left == right)
        {
            tree[root] = data[left];
            return;
        }
        build(leftSubTree(root), left, (left + right) / 2);
        build(rightSubTree(root), (left + right) / 2 + 1, right);
        tree[root] = tree[leftSubTree(root)] + tree[rightSubTree(root)];
    }

    void update(int root, int left, int right, int from, int to, int val = 0)
    {
        if (from > right || to < left)
            return;
        if (left >= from && right <= to)
        { // Implement Here.
            tree[root] += val;
            return;
        }
        update(leftSubTree(root), left, (left + right) / 2, from, to, val);
        update(rightSubTree(root), (left + right) / 2 + 1, right, from, to, val);
        tree[root] = tree[leftSubTree(root)] + tree[rightSubTree(root)];
    }
    int query(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return 0;
        if (left >= from && right <= to)
        { // Implement Here.
            return tree[root];
        }
        return query(leftSubTree(root), left, (left + right) / 2, from, to) +
               query(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
    }
};

void SolveTestCase(const int cno)
{
    int n, q;
    cin >> n >> q;
    vi a(n, 0);
    SegTree tree(a);
    int op, i, j;
    cout << "Case " << cno << ":\n";
    while (q--)
    {
        cin >> op;
        switch (op)
        {
        case 0:
            cin >> i >> j;
            tree.update(1, 0, n-1, i, j, 1);
            break;
        case 1:
            cin >> i >> j;
            
            break;

        default:
            break;
        }
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