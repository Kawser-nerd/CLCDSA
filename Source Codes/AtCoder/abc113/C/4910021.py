N, M = map(int, input().split())
py = []
for _ in range(M):
    py.append(list(map(int, input().split())))
d = {}
now = 0
num = 0
for p, y in sorted(py):
    if now != p:
        now = p
        num = 1
    d[(p, y)] = num
    num += 1
for p, y in py:
    print('{:06d}{:06d}'.format(p, d[(p, y)]))