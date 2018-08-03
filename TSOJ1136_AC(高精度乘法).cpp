#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    char a[10000],b[10000];
    int anum[10000],bnum[10000],cnum[10000];
    while(cin>>a>>b)
    {
        memset(anum,0,sizeof(anum));
        memset(bnum,0,sizeof(bnum));
        memset(cnum,0,sizeof(cnum));
        int alen=strlen(a);
        int blen=strlen(b);
        int len=alen+blen;
        for(int i=0;i<alen;i++)
        {
            anum[i]=a[alen-i-1]-'0';
        }
        for(int i=0;i<blen;i++)
        {
            bnum[i]=b[blen-i-1]-'0';
        }
        for(int i=0;i<alen;i++)
        {
            for(int j=0;j<blen;j++)
            {
                cnum[i+j]+=anum[i]*bnum[j];
                cnum[i+j+1]+=(cnum[i+j])/10;
                cnum[i+j]%=10;
            }
        }
        while(cnum[len]==0)
        {
            len--;
            if(cnum[len]!=0)
            {
            	break;
			}
        }
        for(int i=len;i>=0;i--)
        {
            cout<<cnum[i];
        }
        cout<<endl;
    }
    return 0;
}

