#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n,m,cnt,root[maxn],a[maxn],x,y,k;
struct node
{
	int l,r;
	int sum;
};
node T[maxn*40];
vector<int> v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void update(int l,int r,int &x,int y,int pos)
{
	T[++cnt] = T[y];
	T[cnt].sum++;
	x=cnt;
	if(l==r)
	{
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)
	{
		update(l,m,T[x].l,T[y].l,pos);
	}
	else
	{
		update(m+1,r,T[x].r,T[y].r,pos);
	}
}
int query(int l,int r,int x,int y,int k)
{
	if(l==r)
	{
		return l;
	} 
	int m = (l+r)>>1;
	int sum = T[T[y].l].sum-T[T[x].l].sum;
	if(sum>=k)
	{
		return query(l,m,T[x].l,T[y].l,k);
	}
	else
	{
		return query(m+1,r,T[x].r,T[y].r,k-sum);
	}
} 
void init()
{
	memset(root,0,sizeof(root));
	memset(a,0,sizeof(a));
	T[0].l=T[0].r=T[0].sum=0; 
}
int main()
{
	while(cin>>n>>m)
	{
		init(); 
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=1;i<=n;i++)
		{
			update(1,n,root[i],root[i-1],getid(a[i]));
		}
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>k;
			cout<<v[query(1,n,root[x-1],root[y],k)-1]<<endl;
		}
	}
	return 0;
} 
