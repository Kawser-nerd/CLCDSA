n, m = map(int, input().split())
pys = [list(map(int, input().split())) for _ in range(m)]
map_ = {}
for i, (p, y) in enumerate(pys):
    map_.setdefault(p, [])
    map_[p].append(i)

for val in map_.values():
    val.sort(key=lambda i: pys[i][1])

ans = [None] * m
for key, val in map_.items():
    for num, i in enumerate(val):
        ans[i] = '{:06d}'.format(key) + '{:06d}'.format(num + 1)
for a in ans:
    print(a)