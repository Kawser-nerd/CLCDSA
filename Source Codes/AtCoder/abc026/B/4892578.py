import math
n=int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort(reverse=True)
ans=0
for j in range(0,n,2):
    ans+=a[j]**2
for k in range(1,n,2):
    ans-=a[k]**2
print(ans*math.pi)