import collections
n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for i in range(m)]
smax=collections.Counter(s)
tmax=collections.Counter(t)
ans=[0]
for i,j in smax.items():
    if i in tmax.keys():
        ans+=[smax[i]-tmax[i]]
    else:
        ans+=[j]
print(max(ans))