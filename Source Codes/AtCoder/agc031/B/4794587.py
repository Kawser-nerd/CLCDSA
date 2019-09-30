MOD=10**9+7

N=int(input())
a=[int(input()) for i in range(N)]
last={}
tmp={}

ans=1
x=a[0]
last[x]=0
tmp[x]=1

for i in range(1,N):
    x=a[i]
    last.setdefault(x,i)
    tmp.setdefault(x,0)
    if last[x]!=i-1: ans+=tmp[x]
    last[x]=i
    tmp[x]=ans%MOD
    ans=ans%MOD
    
print(ans)