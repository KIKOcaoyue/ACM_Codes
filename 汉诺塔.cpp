#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 65;
const int INF = 0x3f3f3f3f;
int f[maxn];
void init()
{
	memset(f,INF,sizeof(f));
}
int poww(int a,int b)
{
	int res = 1;
	if(b==0)
	{
		return 1;
	}
	while(b>0)
	{
		if(b&1)
		{
			res *= a;
		}
		a *= a;
		b>>=1;
	}
	return res;
}
void hanoi()
{
	f[1] = 1;
	f[2] = 3;
	for(int i=3;i<=maxn;i++)
	{
		for(int x=1;x<i;x++)
		{
			f[i] = min(f[i],2*f[x]+poww(2,i-x)-1);
		}
	} 
}
int main()
{
	init();
	hanoi();
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",f[n]);
	}
	return 0;
} 
