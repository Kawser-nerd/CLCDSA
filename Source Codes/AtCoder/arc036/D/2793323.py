n, q = map(int, input().split())
ws = [tuple(map(int, input().split())) for _ in range(q)]

union = {x:x for x in range(1, n+1)}
odds = {x:None for x in range(1, n+1)}
def root(n):
    if union[n] == n:
        return n
    union[n] = root(union[n])
    return union[n]

for w, x, y, z in ws:
    rx, ry = root(x), root(y)
    if w == 2:
        print('YES' if rx == ry else 'NO')
    elif z % 2 == 0:
        union[rx] = ry
        if odds[rx] and odds[ry]:
            union[root(odds[rx])] = root(odds[ry])
        else:
            odds[rx] = odds[ry] = odds[rx] or odds[ry]
    else:
        odds[rx] = odds[rx] or ry
        odds[ry] = odds[ry] or rx
        union[rx] = root(odds[ry])
        union[ry] = root(odds[rx])