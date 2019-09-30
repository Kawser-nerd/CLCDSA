from functools import cmp_to_key

n = int(input())
a = list(map(int, input().split()))

def group(a):
    d = {}
    for i, x in enumerate(a):
        d.setdefault(x, []).append(i)
    return list(map(
        lambda x: [x[0], x[1][0], len(x[1])],
        sorted(d.items(), key=cmp_to_key(lambda x, y: x[0] - y[0]), reverse=True)
    ))

ans = [0] * n
g = group(a)
g.append([0, 0, 0])
for c, n in zip(g[:-1], g[1:]):
    ans[c[1]] += (c[0] - n[0]) * c[2]
    n[1] = min(c[1], n[1])
    n[2] += c[2]

[print(a) for a in ans]