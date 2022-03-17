#include <iostream>
#define MAXN 1005
int L[MAXN], R[MAXN], N[MAXN], val[MAXN], size[MAXN], cnt = 1;

void insert(int v, int pos = 1)
{
    size[pos]++;
    if (N[pos] == 0 && L[pos] == 0 && R[pos] == 0)
    {
        val[pos] = v;
        N[pos] = 1;
    }
    else if (v < val[pos])
    {
        if (L[pos] == 0)
        {
            L[pos] = ++cnt;
        }
        insert(v, L[pos]);
    }
    else if (v > val[pos])
    {
        if (R[pos] == 0)
        {
            R[pos] = ++cnt;
        }
        insert(v, R[pos]);
    }
    else
    {
        N[pos]++;
    }
}

void remove(int v, int pos = 1)
{
    size[pos]--;
    if (v < val[pos])
    {
        remove(v, L[pos]);
    }
    else if (v > val[pos])
    {
        remove(v, R[pos]);
    }
    else
        N[pos]--;
}

int countl(int v, int pos = 1)
{
    if (v < val[pos])
        return L[pos] ? countl(v, L[pos]) : 0;
    else if (v > val[pos])
        return size[L[pos]] + N[pos] + (R[pos] ? countl(v, R[pos]) : 0);
    else
        return size[L[pos]];
}

int countg(int v, int pos = 1)
{
    if (v > val[pos])
        return R[pos] ? countg(v, R[pos]) : 0;
    else if (v < val[pos])
        return size[R[pos]] + N[pos] + (L[pos] ? countg(v, L[pos]) : 0);
    else
        return size[R[pos]];
}

int rank(int v)
{
    return countl(v) + 1;
}

int kth(int k, int pos = 1)
{
    if (size[L[pos]] + 1 > k)
        return kth(k, L[pos]);
    else if (size[L[pos]] + N[pos] < k)
        return kth(k - size[L[pos]] - N[pos], R[pos]);
    else
        return val[pos];
}

int pre(int v)
{
    int r = countl(v);
    return kth(r);
}

int suc(int v)
{
    int r = size[1] - countg(v) + 1;
    return kth(r);
}