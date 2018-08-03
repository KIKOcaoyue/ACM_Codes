#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const int mod = 1e9+7;
ll a[maxn],dp[maxn][15],n,m,k;
void init()
{
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
			}
			for(int j=1;j<=m&&j<i;j++)
			{
				if(a[i-j]==a[i])
				{
					for(int l=j;l<=m;l++)
					{
						dp[i][l] = (dp[i][l]-dp[i-j-1][l-j]+mod)%mod;
					}
					break;
				}
			}
		}
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}
