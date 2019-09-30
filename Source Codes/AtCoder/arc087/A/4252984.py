import collections
n=int(input())
a=list(map(int,input().split()))
c=collections.Counter(a)
k=0
for s,t in c.items():
    if t<s:
        k+=t
    else:
        k+=t-s
print(k)