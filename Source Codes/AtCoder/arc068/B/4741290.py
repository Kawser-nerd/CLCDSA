from collections import defaultdict
n=int(input())
d=defaultdict(int)
a=list(map(int,input().split()))
for i in range(n):
    d[a[i]]+=1
c=0
for i in d.values():
    c+=i-1
print(n-2*((c+1)//2))