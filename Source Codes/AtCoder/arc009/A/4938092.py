import math
n=int(input())
ans=0
for i in range(n):
    a,b=[int(i) for i in input().split()]
    ans+=b*a
print(math.floor(ans*1.05))