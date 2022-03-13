#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int dist[400][400];

void Floyed(int n)
{
    for (int k = 1; k <= n;k++)
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = w;
    }

    return 0;
}