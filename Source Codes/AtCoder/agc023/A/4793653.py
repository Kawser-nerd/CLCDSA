N=int(input())
a=list(map(int,input().split()))



dic={0:1}
tmp=0
for i in range(N):
    tmp+=a[i]
    dic.setdefault(tmp,0)
    dic[tmp]+=1



ans=0
for i in dic:
    ans+=dic[i]*(dic[i]-1)//2

print(ans)