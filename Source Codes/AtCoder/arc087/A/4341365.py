N=int(input())
A=list(map(int,input().split()))
import collections
a=collections.Counter(A)
ans=0
for i in a.items():
        if(i[0]!=i[1]):
                ans+=i[1] if(i[1]<i[0]) else (i[1]-i[0])
print(ans)