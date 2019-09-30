import numpy as np
n=int(input())
lis=np.array([0]*(10**6+2))
for i in range(n):
    a,b=map(int,input().split())
    lis[a]+=1
    lis[b+1]-=1
ans=[0]*(10**6+1)
ans[0]=lis[0]
for i in range(1,len(ans)):
    ans[i]+=lis[i]+ans[i-1]
print(max(ans))