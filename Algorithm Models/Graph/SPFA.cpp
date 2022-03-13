#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <limits.h>
using namespace std;
#define MAXM (int)(5e5 + 5)
#define MAXN (int)(1e4 + 5)
#define inf 2147483647
struct Edge
{
    int to, w, next;
} edges[MAXM];

int head[MAXM] = {0}, cnt = 0;
int dist[MAXN];
bool inqueue[MAXN];

inline void add(int from, int to, int w)
{
    edges[++cnt].w = w;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

inline void SPFA(int s)
{
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        inqueue[p] = false;
        for (int e = head[p]; e != 0; e = edges[e].next)
        {
            int to = edges[e].to;
            if (dist[to] > dist[p] + edges[e].w)
            {
                dist[to] = dist[p] + edges[e].w;
                if (!inqueue[to])
                {
                    inqueue[to] = true;
                    Q.push(to);
                }
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    memset(dist, INT_MAX, sizeof(dist));
    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
        inqueue[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dist[s] = 0;
    SPFA(s);
    for (int i = 1; i <= n - 1; i++)
    {
        cout << dist[i] << " ";
    }
    cout << dist[n] << endl;
    return 0;
}
