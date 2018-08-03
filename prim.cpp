#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX_N = 1010;
const int INF = (1<<31)-1;
int map[MAX_N][MAX_N];
int dis[MAX_N];
bool vis[MAX_N];
int n;
int s;
void prim()
{
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
		dis[i]=map[s][i];
	}
	vis[s]=1;
	int sum=0;
	for(int k=0;k<n;k++)
	{
		int mi=INF,pos=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i] & dis[i]<mi)
			{
				mi=dis[i];
				pos=i;
			}
		}
		if(mi==INF)
		{
			break;
		}
		vis[pos]=1;
		sum+=dis[pos];
		for(int i=0;i<n;i++)
		{
			if(!vis[i] && dis[i]>map[pos][i])
			{
				dis[i]=map[pos][i];
			}
		}
	}
	cout<<sum<<endl;
}
int main()
{
	
	return 0;
}
