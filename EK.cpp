#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1<<20;
int G[maxn][maxn];
int Prev[maxn];//路径上每个节点的前驱结点
bool visited[maxn];
int n,m;
int Augment()
{
	int v;
	int i;
	deque<int> q;
	memset(Prev,0,sizeof(Prev));
	memset(visited,0,sizeof(visited));
	Prev[1] = 0;
	visited[1] = 1;
	q.push_back(1);
	bool bFindPath = false;
	while(!q.empty())
	{
		v = q.front();
		q.pop_front();
		for(i=1;i<=m;i++)
		{
			if(G[v][i]>0 && visited[i] == 0)
			{
				Prev[i] = v;
				visited[i] = 1;
				if(i == m)
				{
					bFindPath = true;
					q.clear();
					break;
				}
				else
				{
					q.push_back(i);
				}
			}
		}
	}
	if(!bFindPath)
	{
		return 0;
	}
	int nMinFlow = INF;
	v = m;
	while(Prev[v])
	{
		nMinFlow = min(nMinFlow,G[Prev[v]][v]);
		v = Prev[v];
	}
	v = m;
	while(Prev[v])
	{
		G[Prev[v]][v] -= nMinFlow;
		G[v][Prev[v]] += nMinFlow;
		v = Prev[v];
	}
	return nMinFlow;
} 
int main()
{
	while(cin>>n>>m)
	{
		memset(G,0,sizeof(G));
		for(int i=0;i<n;i++)
		{
			int s,e,c;
			cin>>s>>e>>c;
			G[s][e] += c;
		}
		int MaxFlow = 0;
		int aug;
		while(aug = Augment())
		{
			MaxFlow += aug;
		}
		cout<<MaxFlow<<endl;
	}
	return 0;
}
