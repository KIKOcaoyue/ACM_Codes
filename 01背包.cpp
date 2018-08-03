#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX_N = 20010;
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int w[MAX_N]={0};
		int c[MAX_N]={0};
		int dp[MAX_N]={0};
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",w+i,c+i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>0;j--)
			{
				if(j>=w[i])
				{
					dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
				}
				else
				{
					dp[j]=dp[j];
				}
			} 
		} 
		printf("%d\n",dp[m]);
	}
	return 0;
}
