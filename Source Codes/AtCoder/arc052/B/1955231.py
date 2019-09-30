import math
N,Q = map(int,input().split())
MAXX = 20010
mem = [0] * MAXX
for i in range(N):
    x,r,h = map(int,input().split())
    for j in range(h):
        mem[x+j] += (r*(h-j)/h)**2 * (h-j) - (r*(h-j-1)/h)**2 * (h-j-1)
cums = [0]
for i in range(MAXX):
    cums.append(cums[-1] + mem[i])

for i in range(Q):
    a,b = map(int,input().split())
    print((cums[b]-cums[a]) * math.pi / 3)