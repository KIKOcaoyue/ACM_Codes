#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
typedef long long ll;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
struct node{int l,r,id;}q[maxn];
int a[maxn],ans[maxn],nxt[maxn],head[maxn],n,m;
void add(int x,int y)
{
    for(;x<=n;x+=x&(-x))a[x]+=y;
}
int sum(int x)
{
    int t=0;
    for(;x;x-=x&(-x))t+=a[x];
    return t;
}
bool cmp(node a,node b)
{
    return a.r<b.r;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
     {
         int x=read();
         nxt[i]=head[x];
         head[x]=i;
     }
    m=read();
    for(int i=1;i<=m;i++)
     q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+m+1,cmp);
    int now=0;
    for(int i=1;i<=m;i++)
    {
        while(now<q[i].r)
        {
            now++;
            add(nxt[now]+1,1);
            add(now+1,-1);
        }
        ans[q[i].id]=sum(q[i].l);
    }  
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
