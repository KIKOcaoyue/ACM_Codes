#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
const double INF = 1<<20;
int n,k;
int s[maxn],c[maxn];
double res[maxn];
void init()
{
	memset(s,0,sizeof(s));
	memset(c,0,sizeof(c));
	memset(res,0,sizeof(res));
}
bool isok(double x)
{
	for(int i=1;i<=n;i++)
	{
		res[i] = s[i]*c[i]-x*s[i];
	}
	sort(res+1,res+1+n);
	double ans = 0;
	for(int i=n;i>=k+1;i--)
	{
		ans += res[i];
	}
	double tmp = ans;
	for(int i=k;i>=1;i--)
	{
		ans = max(ans,tmp);
		tmp += res[i];
	}
	return ans>=0;
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",c+i);
		}
		double l=0,r=1e3+7;
		while(r-l>=1e-6)
		{
			double mid = (l+r)/2;
			if(isok(mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		printf("%.5lf\n",l);
	}
	return 0;
}
