#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
ll a[maxn];
ll sum[maxn*3];
ll Add[maxn*3];
void init()
{
	memset(a,0,sizeof(a));
	memset(sum,0,sizeof(sum));
	memset(Add,0,sizeof(Add));
}
void pushup(ll rt)
{
	sum[rt]+=sum[rt<<1]+sum[rt<<1|1];
}
void build(ll L,ll R,ll rt)
{
	if(L==R)
	{
		sum[rt] = a[L];
		return;
	}
	ll m = (L+R)>>1;
	build(L,m,rt<<1);
	build(m+1,R,rt<<1|1);
	pushup(rt);
}

void pushdown(ll rt,ll ln,ll rn)
{
	if(Add[rt])
	{
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
		sum[rt<<1]+=Add[rt]*ln;
		sum[rt<<1|1]+=Add[rt]*rn;
		Add[rt]=0;
	}
}
void update(ll l,ll r,ll L,ll R,ll x,ll rt)
{
	if(l<=L && r>=R)
	{
		sum[rt]+=x*(R-L+1);
		Add[rt]+=x;
		return;
	}
	ll m = (L+R)>>1;
	pushdown(rt,m-L+1,R-m);
	if(l<=m)
	{
		update(l,r,L,m,x,rt<<1);
	}
	if(r>m)
	{
		update(l,r,m+1,R,x,rt<<1|1);
	}
	pushup(rt);
}
ll query(ll l,ll r,ll L,ll R,ll rt)
{
	if(l<=L && r>=R)
	{
		return sum[rt];
	}
	ll m = (L+R)>>1;
	pushdown(rt,m-L+1,R-m);
	ll ans = 0;
	if(l<=m)
	{
		ans += query(l,r,L,m,rt<<1);
	}
	if(r>m)
	{
		ans += query(l,r,m+1,R,rt<<1|1);
	}
	return ans;
}
int main()
{
	ll n,m;
	while(cin>>n>>m)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		build(1,n,1);
		for(int i=0;i<m;i++)
		{
			ll q,l,r,p;
			cin>>q>>l>>r>>p;
			if(q==1)
			{
				update(l,r,1,n,-p,1);
			}
			else
			{
				update(l,r,1,n,p,1);
			}
		}
		ll l,r;
		cin>>l>>r;
		printf("%lld\n",query(l,r,1,n,1));
	}
	return 0;
}
