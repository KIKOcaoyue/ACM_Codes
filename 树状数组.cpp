#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
ll sump[maxn];
ll psum[maxn];
ll n,m; 
void init()
{
	memset(psum,0,sizeof(psum));
	memset(sump,0,sizeof(sump));
}

void add(ll p,ll x)
{
	for(ll i=p;i<=n;i += (i & -i))
	{
		sump[i]+=x;
		psum[i]+=p*x;
	}
}
void add_range(ll l,ll r,ll x)
{
	add(l,x);
	add(r+1,-x);
}
ll query(ll p)
{
	ll ans = 0;
	for(ll i=p;i;i -= (i & -i))
	{
		ans += sump[i]*(p+1)-psum[i];
	}
	return ans;
}
ll query_range(ll l,ll r)
{
	return query(r)-query(l-1);
}
int main()
{
	while(scanf("%lld%lld",&n,&m)!=EOF)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			ll tmp;
			scanf("%lld",&tmp);
			add_range(i,i,tmp);
		}
		for(int i=0;i<m;i++)
		{
			ll q,l,r,p;
			scanf("%lld%lld%lld%lld",&q,&l,&r,&p);
			if(q==1)
			{
				add_range(l,r,-p);
			}
			else
			{
				add_range(l,r,p);
			}
		}
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",query_range(l,r));
	}
	return 0;
} 
