#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    char a[10000],b[10000];
    int anum[10000],bnum[10000];
    int cnum[10000];
    while(cin>>a>>b)
    {
        int pa=0;
        int pb=0;
        int alen=strlen(a);
        int blen=strlen(b);
        for (int i=0;i<=alen-1;i++)
        {
            anum[alen-i]=a[i]-48;
        }

        for (int i=0;i<=blen-1;i++)
        {
            bnum[blen-i]=b[i]-48;
        }
        int num=0;
        int m=1;
        int temp;
        while(m<=alen || m<=blen)
        {
            cnum[m]=anum[m]+bnum[m]+num;
            temp = cnum[m];
            cnum[m]%=10;
            num=temp/10;
            m++;
        }
        while(num)
        {
            cnum[m]=num%10;
            num/=10;
            m++;
        }
        if(cnum[m]==0)
        {
            m--;
        }
        for(int i=m;i>=1;i--)
        {
            cout<<cnum[i];
        }
        cout<<endl;
    }
}