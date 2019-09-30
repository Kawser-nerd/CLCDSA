N, A, B = [int(_) for _ in input().split()]
H = [int(input()) for i in range(N)]

from math import ceil

t = sum(H)

def enough(t):
    r = 0
    for h in H:
        r += ceil(max(h - t * B, 0) / (A - B))
    # print("*", t, r)
    return r <= t

lo = ceil(t / (A + B * (N - 1))) - 1
hi = ceil(t / B)

while lo + 1 != hi:
    t = (lo + hi) // 2
    r = enough(t)
    # print(lo, hi, t, r)
    if r:
        hi = t
    else:
        lo = t

print(hi)