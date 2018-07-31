#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int n,q,tree[maxn],pre[maxn],nxt[maxn],last[maxn],a[maxn],vis[maxn],ans[maxn];
struct node
{
	int l,r;
	int id;
}Q[maxn];
void init()
{
	memset(tree,0,sizeof(tree));
	memset(pre,0,sizeof(pre));
	memset(nxt,-1,sizeof(nxt));
	memset(last,-1,sizeof(last));
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
}
bool cmp(node a,node b)
{
	return a.l<b.l;
}
void add(int p,int x)
{
	for(int i=p;i<=2*n;i += (i & -i))
	{
		tree[i] += x;
	}
}
int query(int p)
{
	int res = 0;
	for(int i=p;i;i -= (i & -i))
	{
		res += tree[i];
	}
	return res;
}
int getsum(int l,int r)
{
	return query(r)-query(l-1);
}
int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			a[i+n]=a[i];
		}
		for(int i=1;i<=2*n;i++)
		{
			if(!vis[a[i]])
			{
				vis[a[i]] = 1;
				pre[i] = pre[i-1]+1;
			}
			else
			{
				pre[i]=pre[i-1];
			}
			if(~last[a[i]])
			{
				nxt[last[a[i]]] = i;
			}
			last[a[i]] = i;
		}
		for(int i=1;i<=q;i++)
		{
			int tl,tr;
			scanf("%d%d",&tl,&tr);
			Q[i].l = tr;
			Q[i].r = tl+n;
			Q[i].id = i;
		}
		sort(Q+1,Q+1+q,cmp);
		int pl = 1;
		for(int i=1;i<=q;i++)
		{
			while(pl<Q[i].l)
			{
				if(nxt[pl])
				{
					add(nxt[pl],1);
				}
				pl++;
			}
			ans[Q[i].id] = getsum(Q[i].l,Q[i].r)+pre[Q[i].r]-pre[Q[i].l-1];
		}
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
} 
