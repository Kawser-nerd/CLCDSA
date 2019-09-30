import math
n,h=map(int,input().split())
a=sorted([list(map(int,input().split()))for i in range(n)],key=lambda x:x[1])[::-1]
r=0
d=0
p=0
k=float("inf")
while p<n:
    r+=a[p][1]
    d=max(d,a[p][0])
    k=min(k,p+1+math.ceil(max(0,(h-r))/d))
    p+=1
    if r>=h:
        break
print(k)