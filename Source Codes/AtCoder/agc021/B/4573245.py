import math

n = int(input())
ps = [tuple(map(int, input().split())) for _ in range(n)]
mp = {tuple(p): i for i, p in enumerate(ps)}

# ????p0p1?????p2?????????, ?????????True, ??????False?????
def ccw(p0, p1, p2):
    return (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p1[1] - p0[1]) * (p2[0] - p0[0]) >= 0   # (????p0p1?????p0p2???) >= 0

# ???????ps??(x, y)????
def convex_hull(ps):
    upper = []
    lower = []
    ps.sort()
    for p in ps:
        while len(lower) > 1 and ccw(lower[-2], lower[-1], p):
            lower.pop()
        lower.append(p)

    for p in ps[::-1]:
        while len(upper) > 1 and ccw(upper[-2], upper[-1], p):
            upper.pop()
        upper.append(p)
    return lower[:-1] + upper[:-1]

ans = [0] * n
ch = convex_hull(ps)
ch += [ch[0]]
ch += [ch[1]]

for pre, now, next in zip(ch, ch[1:], ch[2:]):
    x0 = now[0] - pre[0]
    y0 = now[1] - pre[1]
    x1 = next[0] - now[0]
    y1 = next[1] - now[1]
    ans[mp[tuple(now)]] = math.atan2(x1*y0 - x0*y1, x0*x1 + y0*y1) / (2 * math.pi)  # atan2(??, ??), ??: |u||v|sin?, ??: |u||v|cos?

for a in ans:
    print(a)