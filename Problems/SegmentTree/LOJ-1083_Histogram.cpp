/// Bismillahir-Rahmanir-Rahim
///
/// MD NAZMUS SAKIB
/// CSE@RUET@BD
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_MAX 2000009 // 2e6+9
#define IMAX 1000000009   // 1e9+9

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

    Tuple(const int a, const int b)
    {
        x = a;
        y = b;
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
    int maxrmin = 0;

    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }

    void buildTree(int root, int left, int right)
    {
        if (left == right)
        {
            st[root] = a[left];
            return;
        }
        buildTree(leftSubTree(root), left, (left + right) / 2);
        buildTree(rightSubTree(root), (left + right) / 2 + 1, right);
        st[root] = min(st[leftSubTree(root)], st[rightSubTree(root)]);
    }
    int rangeMin(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return IMAX;
        if (left >= from && right <= to)
            return st[root];
        int lmin = rangeMin(leftSubTree(root), left, (left + right) / 2, from, to);
        int rmin = rangeMin(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
        return min(lmin, rmin);
    }

public:
    SegmentTree(const vi &_a)
    {
        a = _a;
        n = (int)a.size();
        st.assign(4 * n, 0);
        buildTree(1, 0, n - 1);
        //cout << st << nl;
    }
    int maxArea()
    {
        maxrmin = 0;
        vi exl(n), exr(n);
        for (int i = 0; i < n; i++)
        {
            int left = i, right = n-1;
            int pmid, mid = (left+right) / 2;
            int rmin = a[i];
            while (left <= right)
            {
                rmin = rangeMin(1, 0, n-1, i, mid);
                if (rmin < a[i])
                    right = mid - 1;
                else
                    left = mid + 1;
                pmid = mid;
                mid = (left + right) / 2;
            }
            if (rmin == a[i])
                pmid++;
            exr[i] = pmid-i;

            left = 0;
            right = i;
            mid = (left+right)/2;
            pmid = mid;
            rmin = a[i];
            while (left <= right)
            {
                rmin = rangeMin(1, 0, n-1, mid, i);
                if (rmin < a[i])
                    left = mid + 1;
                else
                    right = mid - 1;
                pmid = mid;
                mid = (left+right)/2;
            }
            if (rmin == a[i])
                pmid--;
            exl[i] = i-pmid;
        }
        for (int i=0; i<n; i++)
        {
            maxrmin = max(maxrmin, a[i]*(exl[i]-1+exr[i]));
        }
        return maxrmin;
    }
    int rMinQ(int i, int j)
    {
        return rangeMin(1, 0, n-1, i, j);
    }
};

void SolveTestCase(const ui cno)
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    SegmentTree tree(a);

    cout << "Case " << cno << ':' << ' ';
    cout << tree.maxArea() << nl;
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