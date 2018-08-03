#include<iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int num[1000000];
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
            k=0;
            for(j=0;j<count;j++)
            {
                temp=num[j]*2+k;
                num[j]=temp%10;
                k=temp/10;   
            }
            while(k)
             {
                num[count++]=k%10;
                k/=10;
            }
        }
        if(num[count-1]==0)
        {
        	count--;
		}
		num[0]--;
        for(int i=count-1;i>=0;i--)
        {
        	cout<<num[i];
		}
		cout<<endl;
		
    }
    return 0;
}
