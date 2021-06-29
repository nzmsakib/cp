/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE@RUET@BD
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_MAX 2000009   // 2e6+9
#define IMAX 1000000009     // 1e9+9
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
    int sum, index, value;

    bool operator<(const Tuple &tuple) const
    {
        // Custom sorting function definition goes here.
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
    }
    return out;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree
{
private:
    vt st, a;

    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }

public:
    int n;
    SegmentTree(const int _n)
    {
        n = _n;
        st.assign(4 * n, Tuple());
    }
    SegmentTree(const vt &_a)
    {
        a = _a;
        n = (int)a.size();
        st.assign(4 * n, Tuple());
        build(1, 0, n - 1);
    }
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

    void update(int root, int left, int right, int index, int value, int visited)
    {
        if (left == right)
        { // Implement Here.
            st[root].sum = visited;
            st[root].value = value;
            st[root].index = index;
            return;
        }
        if (index <= (left + right) / 2)
            update(leftSubTree(root), left, (left + right) / 2, index, value, visited);
        else
            update(rightSubTree(root), (left + right) / 2 + 1, right, index, value, visited);
        st[root].sum = st[leftSubTree(root)].sum + st[rightSubTree(root)].sum;
    }
    int query(int root, int left, int right, int index)
    {
        st[root].sum--;
        if (left == right)
            return st[root].value;
        if (index <= st[leftSubTree(root)].sum)
            return query(leftSubTree(root), left, (left + right) / 2, index);
        else
            return query(rightSubTree(root), (left + right) / 2 + 1, right, index - st[leftSubTree(root)].sum);
    }
    Tuple get(int i) { return st[i]; }
};

void SolveTestCase(const ui cno)
{
    int n, q, x;
    cin >> n >> q;
    int m = n+q;
    vi a(n);
    cin >> a;

    SegmentTree tree(m);
    for (int i = 0; i < n; i++)
    {
        tree.update(1, 0, m-1, i+1, a[i], 1);
    }

    cout << "Case " << cno << ':' << nl;
    for (int i = 0; i < q; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        // cout << c << ' ' << x << nl;
        if (c == 'a')
        {
            a.push_back(x);
            n++;
            tree.update(1, 0, m-1, n, x, 1);
        }
        else
        {
            if (tree.get(1).sum < x)
                cout << "none" << nl;
            else cout << tree.query(1, 0, m-1, x) << nl;
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
    for (ui i = 1; i <= t; i++)
        SolveTestCase(i);
}