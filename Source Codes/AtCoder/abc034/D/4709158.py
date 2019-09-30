from operator import itemgetter

n, k = map(int, input().split())
wp = [tuple(int(x) for x in input().split()) for _ in range(n)]

L = 0.0
H = 100.0

while (H - L) > 1e-10:
    M = (H + L) / 2
    p = [[0,0] for _ in range(n)]
    for i in range(n):
        p[i] = [i, wp[i][0] * (wp[i][1] - M) / 100.0]
    p.sort(key=itemgetter(1), reverse=True)
    w = 0
    s = 0
    for i in range(k):
        w += wp[p[i][0]][0]
        s += wp[p[i][0]][0] * wp[p[i][0]][1] / 100.0
    temp = s / w * 100
    if temp > M:
        L = M
    elif temp < M:
        H = M
    else:
        break

print(M)