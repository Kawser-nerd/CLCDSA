h, w, d = [int(i) for i in input().split(" ")]
a = [[] for i in range(0, h)]

for i in range(0, h):
    a[i] = [int(j) for j in input().split(" ")]

q = int(input())
l = []
r = []

for i in range(0, q):
    li, ri = [int(i) for i in input().split(" ")]
    l.append(li)
    r.append(ri)

cor = [[0, 0] for i in range(0, h * w + 1)]
s = [0] * (h * w + 1)

for i in range(0, h):
    for j in range(0, w):
        cor[a[i][j]] = [i, j]

def mp(p, q):
    global cor
    return abs(cor[p][0] - cor[q][0]) +  abs(cor[p][1] - cor[q][1])

for m in range(1, d + 1):
    x = m + d
    while x <= h * w:
        s[x] = s[x - d] + mp(x, x - d)
        x += d

for i in range(0, q):
    print(s[r[i]] - s[l[i]])