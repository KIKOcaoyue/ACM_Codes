#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX_N = 100100;
int BIT[MAX_N]={0};
int n,m,t;
void add(int i,int x)
{
	while(i<=n)
	{
		BIT[i]+=x;
		i += (i & -i);
	}
}
int sum(int i)
{
	int result=0;
	while(i>0)
	{
		result+=BIT[i];
		i -= (i & -i);
	}
	return result;
}
int main()
{
	
	return 0;
}
