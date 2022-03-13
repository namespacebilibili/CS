#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dist[400];
struct Edge
{
    int from, to, w, next;
} edges[400];
int head[400], cnt = 0;
inline void add(int from, int to, int w)
{
    edges[++cnt].to = to;
    edges[cnt].from = from;
    edges[cnt].w = w;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

inline void Bellman_Ford(int n, int m)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            dist[edges[i].to] = min(dist[edges[i].to], dist[edges[i].from] + edges[i].w);
        }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < m; i++)
    { 
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    Bellman_Ford(n, m);
    return 0;
}
