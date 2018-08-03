#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 1<<31-1;
const int MAX_N = 1010;
int S,T;
int n,m;
struct edge
{
	int to,cap,rev;
};
vector<edge> G[MAX_N];
int depth[MAX_N];
int arc[MAX_N];
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s)
{
	queue<int> q;
	memset(depth,-1,sizeof(depth));
	depth[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e = G[v][i];
			if(e.cap>0 && depth[e.to]<0)
			{
				depth[e.to] = depth[v] + 1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{
	if(v==t)
	{
		return f;
	}
	for(int &i=arc[v];i<G[v].size();i++)
	{
		edge &e = G[v][i];
		if(e.cap>0 && depth[v]+1==depth[e.to])
		{
			int d = dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{
	int flow = 0;
	while(true)
	{
		bfs(s);
		if(depth[t]<0)
		{
			return flow;
		}
		memset(arc,0,sizeof(arc));
		int f;
		while((f=dfs(s,t,INF))>0)
		{
			flow+=f;
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			int s,e,c;
			cin>>s>>e>>c;
			add_edge(s,e,c);
		}
		S=1;
		T=4;
		cout<<max_flow(S,T)<<endl;
	}
	return 0;
} 
