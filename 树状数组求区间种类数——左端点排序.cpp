#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
	int l,r,id;
}q[maxn];
int a[maxn],ans[maxn],nxt[maxn],head[maxn],n,m,mx,b[maxn];
void add(int x,int y)
{
    for(;x<=n;x+=x&(-x))
		a[x]+=y;
}
int sum(int x)
{
    int t=0;
    for(;x;x-=x&(-x))t+=a[x];
    return t;
}
bool cmp(node a,node b)
{
    return a.l==b.l?a.r<b.r:a.l<b.l;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=n;i>=1;i--)
    {
        nxt[i]=head[b[i]];
        head[b[i]]=i;
        mx=max(mx,b[i]);
    }
    m=read();
    for(int i=1;i<=m;i++)
     	q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+m+1,cmp);
    for(int i=1;i<=mx;i++)if(head[i])add(head[i],1);
    int now=1;
    for(int i=1;i<=m;i++)
    {
        while(now<q[i].l)
        {
            if(nxt[now])add(nxt[now],1); 
            now++;
        }
        ans[q[i].id]=sum(q[i].r)-sum(q[i].l-1);
    }  
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
