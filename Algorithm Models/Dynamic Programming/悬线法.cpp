#include<iostream>
#include<cmath>
#define MAXN (int)2005
class Solution
{
public:
    int n, m, a[MAXN][MAXN];
    void input()
    {
        using namespace std;
        cin >> n >> m;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
    }
    int solve()
    {
        using namespace std;
        int l[MAXN][MAXN] = {0}, r[MAXN][MAXN] = {0}, u[MAXN][MAXN] = {0};
        /*
            u[i][j]:从(i,j)最多能往上走多少格;
            l[i][j]:从(i,j)最多能往左走多少格;
            r[i][j]:从(i,j)最多能往右走多少;
            L[i][j]:从(i,j)向上的悬线最多能往左走多少格;
            R[i][j]:从(i,j)向上的悬线最多能往右走多少格;
            有:L[i][j]=a[i-1][j]?min(l[i][j],L[i-1][j]):l[i][j];
              R[i][j]=a[i-1][j]?min(r[i][j],R[i-1][j]):r[i][j];
            发现L(R)数组可以和l(r)数组合并.
        */
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1;j<=m;j++)
            {
                if(a[i][j])
                    l[i][j] = l[i][j - 1] + 1;
            }
        }
        for (int i = 1; i <= n;i++)
        {
            for (int j = m; j >= 1;j--)
            {
                if(a[i][j])
                    r[i][j] = r[i][j + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m;j++)
            {
                if(a[i][j])
                {
                    u[i][j] = u[i - 1][j] + 1;
                    if(a[i-1][j])
                    {
                        l[i][j] = min(l[i][j], l[i - 1][j]);
                        r[i][j] = min(r[i][j], r[i - 1][j]);
                    }
                    ans = max(ans, (r[i][j] + l[i][j] - 1) * u[i][j]);
                }
            }
        }
        return ans;
    }
};