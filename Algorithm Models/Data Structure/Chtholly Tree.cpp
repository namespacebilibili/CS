/*
1 l r x: For each i such that l ≤ i ≤ r, assign ai + x to ai.
2 l r x: For each i such that l ≤ i ≤ r, assign x to ai.
3 l r x: Print the x-th smallest number in the index range [l, r], i.e. the element at the x-th position if all the elements ai such that l ≤ i ≤ r are taken and sorted into an array of non-decreasing integers. It's guaranteed that 1 ≤ x ≤ r - l + 1.
4 l r x y: Print the sum of the x-th power of ai such that l ≤ i ≤ r, modulo y.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#define ll long long
using namespace std;

/*
CF915E Physical Education Lessons:
*/
ll n, sum, q;

ll qpow(ll a, ll n, ll p)
{
    ll ans = 1;
    a %= p;
    while (n)
    {
        if (a & 1)
            ans = ans * a % p;
        n >>= 1;
        a = a * a % p;
    }
    return ans;
}

class Node
{
public:
    ll l, r;
    mutable ll v;
    Node(ll l, ll r, ll v) : l(l), r(r), v(v) {}
    bool operator<(const Node &o) const { return l < o.l; };
};

class Chtholly_Tree
{
public:
    set<Node> tree;
    set<Node>::iterator split(ll pos);
    void assign(ll l, ll r, ll v);
    void add(ll l, ll r, ll v);
    ll kth(ll l, ll r, ll k);
    ll sum_of_pow(ll l, ll r, ll x, ll y);
};

set<Node>::iterator Chtholly_Tree::split(ll pos)
{
    auto it = tree.lower_bound(Node(pos, 0, 0));
    if (it != tree.end() && it->l == pos)
        return it;
    it--;
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it);
    tree.insert(Node(l, pos - 1, v));
    return tree.insert(Node(pos, r, v)).first;
}

void Chtholly_Tree::assign(ll l, ll r, ll v)
{
    ll tot = 0, len = 0;
    auto end = split(r + 1), begin = split(l);
    for (auto it = begin; it != end; it++)
    {
        len += (it->r - it->l + 1);
        tot += it->v * (it->r - it->l + 1);
    }
    tree.erase(begin, end);
    tree.insert(Node(l, r, v));
    if (v == 1)
        sum += (len - tot);
    else
        sum -= tot;
}

void Chtholly_Tree::add(ll l, ll r, ll v)
{
    auto end = split(r + 1);
    for (auto it = split(l); it != end; it++)
        it->v += v;
}

ll Chtholly_Tree::kth(ll l, ll r, ll k)
{
    auto end = split(r + 1);
    vector<pair <ll, ll> > v;
    for (auto it = split(l); it != end; it++)
        v.push_back(make_pair(it->v, it->r - it->l + 1));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        k -= v[i].second;
        if (k <= 0)
            return v[i].first;
    }
    return 0;
}

ll Chtholly_Tree::sum_of_pow(ll l, ll r, ll x, ll y)
{
    ll tot = 0;
    auto end = split(r + 1);
    for (auto it = split(l); it != end; it++)
        tot = (tot + qpow(it->v, x, y) * (it->r - it->l - 1)) % y;
    return tot;
}

int main()
{
    cin >> n >> q;
    Chtholly_Tree t;
    t.tree.insert(Node(1, n, 1));
    sum = n;
    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        t.assign(l, r, k == 1 ? 0 : 1);
        cout << sum << endl;
    }
    return 0;
}