#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
inline ll find_k_muti(ll x,ll y,int k)
{
	return (y/k-(x-1)/k);
}
int main()
{
	ll a,b,c,d;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF)
	{
		ll ans=0;
		ans+=(b-a+1-find_k_muti(a,b,1009))*find_k_muti(c,d,2018);
		ans+=find_k_muti(a,b,2018)*(d-c+1-find_k_muti(c,d,1009));
		ans+=(find_k_muti(a,b,2)-find_k_muti(a,b,2018))*(find_k_muti(c,d,1009)-find_k_muti(c,d,2018));
		ans+=(find_k_muti(c,d,2)-find_k_muti(c,d,2018))*(find_k_muti(a,b,1009)-find_k_muti(a,b,2018));
		ans+=(find_k_muti(a,b,1009))*(find_k_muti(c,d,2018));
		ans+=(find_k_muti(c,d,1009))*(find_k_muti(a,b,2018));
		ans-=find_k_muti(a,b,2018)*find_k_muti(c,d,2018);
		cout<<ans<<endl; 
	}
	return 0;
}
