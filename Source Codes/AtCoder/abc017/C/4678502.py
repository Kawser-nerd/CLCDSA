from itertools import accumulate as ac
a,b=map(int,input().split())
d=[0]*(b+1)
k=0
for i in range(a):
    e,f,g=map(int,input().split())
    d[e-1]+=g
    d[f]-=g
    k+=g
p=list(ac(d))[:-1]
print(k-min(p))