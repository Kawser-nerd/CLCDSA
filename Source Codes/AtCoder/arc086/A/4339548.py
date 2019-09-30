N,K=map(int,input().split())
A=list(map(int,input().split()))
import collections
a=collections.Counter(A)
a=sorted(a.items(),key=lambda x:x[1])
k=len(a)
ans=0
i=0
while k>K:
        ans+=a[i][1]
        i+=1
        k-=1
print(ans)