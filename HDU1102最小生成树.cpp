#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int INF = 1<<20;
int mp[maxn][maxn],dis[maxn],intree[maxn];
int n,m;
void init()
{
	memset(mp,INF,sizeof(mp));
	memset(dis,0,sizeof(dis));
	memset(intree,0,sizeof(intree));
}
int prim(int s)
{
	for(int i=0;i<n;i++)
	{
		intree[i]=0;
		dis[i]=mp[s][i];
	}
	intree[s]=1;
	int sum = 0;
	for(int k=0;k<n;k++)
	{
		int mi = INF,pos = 0;
		for(int i=0;i<n;i++)
		{
			if(!intree[i] && dis[i]<mi)
			{
				mi = dis[i];
				pos = i;
			}
		}
		if(mi==INF)
		{
			break;
		}
		intree[pos]=1;
		sum+=dis[pos];
		for(int i=0;i<n;i++)
		{
			if(!intree[i]&&dis[i]>mp[pos][i])
			{
				dis[i]=mp[pos][i];
			}
		}
	}
	return sum;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			mp[a][b]=0;
			mp[b][a]=0; 
		}
		printf("%d\n",prim(0));
	}
	return 0;
}
