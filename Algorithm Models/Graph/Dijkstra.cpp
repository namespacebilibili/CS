#include <iostream>
#include<queue>

const int MaxN = 100010, MaxM = 500010;

struct edge
{
    int to, d, next;
}edges[MaxM];

int head[MaxN], dist[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

inline void add(int from, int to, int d)
{
    cnt++;
    edges[cnt].d = d;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

struct Polar
{
    int d;
    int id;
    bool operator<(const Polar &x) const
    {
        return x.d < d;
    }
};

std::priority_queue<Polar> q;

inline void dijkstra()
{
    dist[s] = 0;
    q.push((Polar){0, s});
    while (!q.empty())
    {
        int x=q.top().id;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = edges[i].next)
        {
            int y = edges[i].to;
            if (dist[y] > dist[x] + edges[i].d)
            {
                dist[y] = dist[x] + edges[i].d;
                if (!vis[y])
                {
                    q.push((Polar){dist[y], y});
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; ++i)
        dist[i] = 0x7fffffff;
    for (register int i = 0; i < m; ++i)
    {
        register int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add(u, v, d);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    return 0;
}