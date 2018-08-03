#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int f[1010][1010]={0};
void ST(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		f[i][0]=a[i];
	}
	int nlog = int(log(double(len))/log(2.0));
	for(int j=1;j<=nlog;j++)
	{
		for(int i=0;i<len;i++)
		{
			if(i+(1<<j)-1<len)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int RMQ(int *a,int len,int s,int e)
{
	int nlog = (int)(log(double(e-s+1)/log(2.0)));
	return min(f[s][nlog],f[e-(1<<nlog)+1][nlog]);
}
int main()
{
	int nArr[6] = {5,4,6,10,1,12};
    ST(nArr,6);
    cout<<RMQ(nArr,6,0,5)<<endl;
    cout<<RMQ(nArr,6,1,3)<<endl;
    cout<<RMQ(nArr,6,2,5)<<endl;
    cout<<RMQ(nArr,6,2,2)<<endl;
	return 0;
}
