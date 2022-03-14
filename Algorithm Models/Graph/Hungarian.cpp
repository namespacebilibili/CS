/*
https://www.luogu.com.cn/problem/P1129
*/
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 205
#define MAXM 205
int M, N;
int Map[MAXM][MAXN];
int p[MAXN];
bool vis[MAXN];

bool match(int i)
{
    for (int j = 1; j <= N; j++)
    {
        if (Map[i][j] && !vis[j])
        {
            vis[j] = true;
            if (p[j] == 0 || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; i++)
    {
        memset(vis, false, sizeof(vis));
        if (match(i))
            cnt++;
    }
    return cnt;
}

int T;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> N;
        M = N;
        memset(p, 0, sizeof(p));
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N;j++)
                cin >> Map[i][j];
        }
        if(Hungarian()==N)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}