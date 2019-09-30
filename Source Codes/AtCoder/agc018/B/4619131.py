import sys
input=sys.stdin.readline
from collections import Counter
n,m=map(int,input().split())
A,B=[],[]
for _ in range(n):
    A.append(tuple(map(lambda x:int(x)-1,input().split())))
    B.append(A[-1][0])
delete=[False]*m
ans=n
idx=[0]*n
for _ in range(m-1):
    c=Counter(B)
    sport,num=c.most_common()[0]
    ans=min(ans,num)
    delete[sport]=True
    for i in range(n):
        while delete[A[i][idx[i]]]:
            idx[i]+=1
        B[i]=A[i][idx[i]]
print(ans)