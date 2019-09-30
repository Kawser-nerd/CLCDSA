from itertools import accumulate as ac
n,m=map(int,input().split())
s=[0]*(n+1)
p=[list(map(int,input().split()))for i in range(m)]
for i in range(m):
    s[p[i][0]-1]+=1
    s[p[i][1]]-=1
s=list(ac(s))[:-1]
s=[(1 if i==1 else 0)for i in s]
s=[0]+list(ac(s))
k=[]
for i in range(m):
    if s[p[i][1]]-s[p[i][0]-1]==0:
        k.append(i+1)
print(len(k))
for i in k:
    print(i)