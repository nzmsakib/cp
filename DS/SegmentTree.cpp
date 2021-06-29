#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegTree
{
private:
    int n;
    int leftSubTree(int node) { return node << 1; }
    int rightSubTree(int node) { return (node << 1) + 1; }
    vi tree;
public:
    SegTree(const vi &a)
    {
        n = a.size();
        tree.assign(4*n, 0);
    }
    void build(int root, int left, int right)
    {
        if (left == right)
        {
        }
        build(leftSubTree(root), left, (left + right) / 2);
        build(rightSubTree(root), (left + right) / 2 + 1, right);
    }

    void update(int root, int left, int right, int from, int to, int val = 0)
    {
        if (from > right || to < left)
            return;
        if (left >= from && right <= to)
        { // Implement Here.
        }
        update(leftSubTree(root), left, (left + right) / 2, from, to);
        update(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
        return;
    }
    int query(int root, int left, int right, int from, int to)
    {
        if (from > right || to < left)
            return 0;
        if (left >= from && right <= to)
        { // Implement Here.
        }
        return query(leftSubTree(root), left, (left + right) / 2, from, to) +
               query(rightSubTree(root), (left + right) / 2 + 1, right, from, to);
    }
};