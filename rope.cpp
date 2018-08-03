#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		rope<int> r,tmp;
		for(int i=1;i<=n;i++)
		{
			r.push_back(i);
		}
		for(int i=0;i<m;i++)
		{
			int pos,l;
			scanf("%d%d",&pos,&l);
			tmp = r.substr(pos-1,l);
			r.erase(pos-1,l);
			r.insert(0,tmp);
		}
		for(int i=0;i<r.size();i++)
		{
			cout<<r[i];
			if(i<r.size()-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} 
