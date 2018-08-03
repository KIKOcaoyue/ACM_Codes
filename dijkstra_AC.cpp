#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX_N = 1010;
const int INF = (1<<31)-1;
vector<pair<int,int> >G[MAX_N];
int d[MAX_N];
void init()
{
	for(int i=0;i<MAX_N;i++)
	{
		G[i].clear();
	}
	fill(d,d+MAX_N,INF);
}
void bfs(int s)
{
	priority_queue<pair<int,int> >q;
	q.push(P(-d[s],s));
	while(!q.empty())
	{
		int now = q.top().second;
		q.pop();
		for(int i=0;i<G[now].size();i++)
		{
			int v = G[now][i].first;
			if(d[v]>d[now]+G[now][i].second)
			{
				d[v]=d[now]+G[now][i].second;
				q.push(P(-d[v],v));
			}
		}
	}
}
int n,m;
int main()
{
	while(cin>>n>>m)
	{
		init();
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			G[a].push_back(P(b,c));
			G[b].push_back(P(a,c));
		}
		int s,t;
		cin>>s>>t;
		d[s]=0;
		bfs(s);
		if(d[t]==INF)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<d[t]<<endl;
		}
	}
	return 0;
}
