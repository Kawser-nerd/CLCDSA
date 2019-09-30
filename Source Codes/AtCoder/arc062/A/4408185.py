N = int(input())
TA = []
for _ in range(N):
    t, a = map(int, input().split())
    TA.append([t, a])

t0, a0 = 1, 1
for t, a in TA:
    t0 = -(-t0 // t) * t
    a0 = -(-a0 // a) * a
    if t0 / a0 < t / a:
        t0 = t * a0 // a
    else:
        a0 = a * t0 // t

ans = t0 + a0
print(ans)