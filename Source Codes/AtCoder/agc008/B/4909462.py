from itertools import accumulate as ac
n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[0]+list(ac(a))
c=[0]+list(ac([(0 if i<0 else i)for i in a]))
d=0
for i in range(n-k+1):
    d=max(d,max(b[i+k]-b[i],0)+c[i]+c[-1]-c[i+k])
print(d)