N,L,T = map(int,input().split())
src = [tuple(map(int,input().split())) for i in range(N)]

xs = []
for x,w in src:
    dx = T if w==1 else -T
    xs.append((x+dx) % L)
xs.sort()

if N == 1:
    print(xs[0])
    exit()

x0,w0 = src[0]
k0 = 0
for x,w in src:
    if x == x0: continue
    if w == w0: continue
    if w0 == 1:
        dist = (x-x0) % L
    else:
        dist = (x0-x) % L
    if 2*T >= dist:
        k0 += 1 + (2*T-dist)//L

newx0 = (x0+T)%L if w0==1 else (x0-T)%L
i0 = xs.index(newx0)
if w0 == 1 and i0+1 < N and xs[i0] == xs[i0+1]:
    i0 += 1
i0 += (k0 if w0==2 else -k0)
i0 %= N

for i in range(i0,i0+N):
    print(xs[i%N])