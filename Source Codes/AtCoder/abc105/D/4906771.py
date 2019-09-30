import sys
N,M=map(int,input().split())
a=list(map(int,input().split()))
dic={0:1}
tmp=0
for i in range(N):
    tmp=(tmp+a[i])%M
    if tmp in dic: dic[tmp]+=1
    else:dic.setdefault(tmp,1)
ans=0
for i in dic: ans+=dic[i]*(dic[i]-1)//2
print(ans)