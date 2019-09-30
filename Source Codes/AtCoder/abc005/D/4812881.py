from itertools import accumulate

n = int(input())
board = [list(map(int, input().split())) for i in range(n)]
q = int(input())
ps = [int(input()) for i in range(q)]

for i in range(n):
    for j in range(n-1):
        board[i][j+1] += board[i][j]
for i in range(n):
    for j in range(n-1):
        board[j+1][i] += board[j][i]


d = {}
for i in range(n):
    for j in range(i, n):
        for k in range(n):
            for l in range(k, n):
                area = (j-i+1)*(l-k+1)
                s = board[j][l]
                if k:
                    s -= board[j][k-1]
                if i:
                    s -= board[i-1][l]
                if i*k:
                    s += board[i-1][k-1]
                d[area] = max(d.get(area, 0), s)
# ??max???
v = [0]*(n**2+1)
for area, oishisa in d.items():
    v[area] = oishisa
v = list(accumulate(v, max))
for p in ps:
    print(v[p])