from math import hypot
N = int(input())
A = [tuple(map(int,input().split())) for i in range(N)]
B = [tuple(map(int,input().split())) for i in range(N)]

sx = sy = 0
for ax,ay in A:
    sx += ax
    sy += ay
gxa = sx / N
gya = sy / N

sx = sy = 0
for bx,by in B:
    sx += bx
    sy += by
gxb = sx / N
gyb = sy / N

c1 = 0
for ax,ay in A:
    c1 += hypot(ax-gxa, ay-gya)

c2 = 0
for bx,by in B:
    c2 += hypot(bx-gxb, by-gyb)

print(c2/c1)