#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int x=0,y=0;
int extgcd(int a,int b,int &x,int &y)
{
	int d=a;
	if(b!=0)
	{
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else
	{
		x=1;
		y=0;
	}
	return d;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<extgcd(a,b,x,y)<<endl;
		cout<<"x="<<x<<","<<"y="<<y<<endl;
	}
	return 0;
}
