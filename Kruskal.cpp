#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int p[maxn];
int n;
void init()
{
	for(int i=0;i<n;i++)
	{
		p[i]=i;
	}
}
int find(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	else
	{
		return p[x]=find(p[x]);
	}
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return;
	}
	p[x]=y;
}
struct edge
{
	int u,v,cost;
};
bool cmp(const edge &e1,const edge &e2)
{
	return e1.cost < e2.cost;
}
edge es[maxn];
int V,E;
int kruskal()
{
	sort(es,es+E,cmp);
	init();
	int res=0;
	for(int i=0;i<E;i++)
	{
		edge e = es[i];
		if(!find(e.u,e.v))
		{
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
	
	return 0;
} 
