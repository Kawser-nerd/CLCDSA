from sys import exit
from math import ceil
N,H = [int(n) for n in input().split()]
ab = [(0,0)]*N
maxa = 0#?????
ans = 0
for i in range(N):
    ab[i] = tuple(int(n) for n in input().split())
    maxa = max(maxa, ab[i][0])
ab = sorted(ab,key= lambda x:-x[1])
for katana in ab:
    if katana[1] > maxa:
        H-=katana[1]
        ans+=1
        if(H<=0): break
    else:
        break

if(H<=0):
    print(ans)
else:
    print(ans + ceil(H/maxa))