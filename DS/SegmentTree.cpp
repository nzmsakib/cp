#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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
            
        }
        if (left != right)
        {
            update(leftSubTree(root), left, (left + right) / 2, from, to);
            update(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
            return;
        }
    }
    int query(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return 0;
        if (left >= from && right <= to)
        { // Implement Here.

        }
        if (left != right)
        {
           return st[root] + query(leftSubTree(root), left, (left + right) / 2, from, to) +
            query(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
        }
    }

public:
    SegmentTree(const vi &_a)
    {
        a = _a;
        n = (int)a.size();
        st.assign(4 * n, 0);
    }
    int query(int i, int j)
    {
        query(1, 0, n-1, i, j);
    }
    void update(int i, int j)
    {
        update(1, 0, n-1, i, j);
    }
};