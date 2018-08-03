#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX_N = 1010;
const int INF = (1<<31)-1; 
int cost[MAX_N][MAX_N];
int mincost[MAX_N];
bool used[MAX_N];
int V;
void init()
{
	fill(mincost,mincost+V,INF);
	fill(used,used+V,0);
}
int prim()
{
	init();
	mincost[0]=0;
	int res=0;
	while(true)
	{
		int v = -1;
		for(int u=0;u<V;u++)
		{
			if(!used[u] && (v==-1 || mincost[u]<mincost[v]))
			{
				v=u;
			}
		}
		if(v==-1)
		{
			break;
		}
		used[v]=true;
		res+=mincost[v];
		for(int u=0;u<V;u++)
		{
			mincost[u]=min(mincost[u],cost[v][u]);
		}
	}
	return res;
}
int main()
{
	
	return 0;
}
