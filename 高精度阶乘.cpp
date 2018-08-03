#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int num[100000];
int main()
{
    int n;
    int i,j,k,count,temp;
    int a,b;
    while(cin>>n)
    {
    	memset(num,0,sizeof(num));
        num[0]=1;
        count=1;
        for(i=1;i<=n;i++)
        {
            k=0;  //
            for(j=0;j<count;j++)
            {
                temp=num[j]*3+k;
                num[j]=temp%10;      
                k=temp/10;
            }
            while(k)
            {
                num[count++]=k%10;
                k/=10;
            }
        }
        while(num[count]==0)
        {
        	count--;
        	if(num[count]!=0)
        	{
        		break;
			}
		}
        for(int i=count;i>=0 ;i--)
        {
        	cout<<num[i];
		}
		cout<<endl;
    }
    return 0;
}
