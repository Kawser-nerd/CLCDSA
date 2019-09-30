import cmath, sys
t_x, t_y = map(int, input().split())
N = int(input())
poly = [list(map(int, e.split())) for e in sys.stdin]
ans = 10000
for i in range(N):
    p1, p2 = poly[i-1], poly[i]
    p = complex(p2[0] - p1[0], p2[1] - p1[1])
    t = complex(t_x - p1[0], t_y - p1[1])
    t *= p.conjugate() / abs(p)
    dist = abs(t.imag)
    if dist < ans:
        ans = dist
print(ans)