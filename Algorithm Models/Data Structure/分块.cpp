/*

*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
const int MAXN = 1000005, SQ = 1005;
int st[SQ], ed[SQ], size[SQ], bel[MAXN];

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = ((s << 3) + (s << 1) + (ch ^ 48)), ch = getchar();
    return s * w;
}

void init_block(int n)
{
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        st[i] = n / sq * (i - 1) + 1;
        ed[i] = n / sq * i;
    }
    ed[sq] = n;
    for (int i = 1; i <= sq; i++)
        for (int j = st[i]; j <= ed[i]; j++)
            bel[j] = i;
    for (int i = 1; i <= sq; i++)
        size[i] = ed[i] - st[i] + 1;
}

int A[MAXN], mark[SQ];
std::vector<int> v[SQ];

void update(int b)
{
    for (int i = 0; i <= size[b]; i++)
        v[b][i] = A[st[b] + i];
    std::sort(v[b].begin(), v[b].end());
}
int main()
{
    int n = read(), m = read();
    int sq = sqrt(n);
    init_block(n);
    for (int i = 1; i <= n; i++)
        A[i] = read();
    for (int i = 1; i <= sq; i++)
        for (int j = st[i]; j <= ed[i]; j++)
            v[i].push_back(A[j]);
    for (int i = 1; i <= sq; i++)
        sort(v[i].begin(), v[i].end());
    while (m--)
    {
        char o;
        scanf("%c", &o);
        int l = read(), r = read(), k = read();
        if (o == 'M')
        {
            if (bel[l] == bel[r])
            {
                for (int i = l; i <= r; i++)
                    A[i] += k;
                update(bel[l]);
                continue;
            }
            for (int i = l; i <= ed[bel[l]]; i++)
                A[i] += k;
            for (int i = st[bel[r]]; i <= r; i++)
                A[i] += k;
            update(bel[l]);
            update(bel[r]);
            for (int i = bel[l] + 1; i < bel[r]; i++)
                mark[i] += k;
        }
        else
        {
            int tot = 0;
            if (bel[l] == bel[r])
            {
                for (int i = l; i <= r; i++)
                {
                    if (A[i] + mark[i] >= k)
                        tot++;
                }
                printf("%d\n", tot);
                continue;
            }
            for (int i = l; i <= ed[bel[l]]; i++)
                if (A[i] + mark[bel[l]] >= k)
                    tot++;
            for (int i = st[r]; i <= r; i++)
                if (A[i] + mark[bel[r]] >= k)
                    tot++;
            for (int i = bel[l] + 1; i < bel[r]; i++)
                tot += v[i].end() - std::lower_bound(v[i].begin(), v[i].end(), k - mark[i]);
            printf("%d\n", tot);
        }
    }
    return 0;
}