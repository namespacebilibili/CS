#include<iostream>
#define MAXN 1005
using namespace std;

struct Edge
{
    int to, w, next;
} edges[MAXN];
int head[MAXN], cnt;
inline void add(int from, int to, int w)
{
    edges[++cnt].w = w;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

int main()
{
    int m;
    while(m--)
    {
        int f, t, w;
        cin >> f >> t >> w;
        add(f, t, w);
    }
    for (int e = head[2]; e != 0; e = edges[e].next)
    {
        printf("%d", edges[e].to);
    }
    return 0;
}
