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
int inq[MAX_N];
void init()
{
	for(int i=0;i<MAX_N;i++)
	{
		G[i].clear();
	}
	fill(d,d+MAX_N,INF);
	fill(inq,inq+MAX_N,0);
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		inq[now]=0;
		for(int i=0;i<G[now].size();i++)
		{
			int v = G[now][i].first;
			if(d[v]>d[now]+G[now][i].second)
			{
				d[v]=d[now]+G[now][i].second;
				if(!inq[v])
				{
					inq[v]=1;
					q.push(v);
				}
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
