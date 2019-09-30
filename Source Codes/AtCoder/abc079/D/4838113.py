N = 10
h, w = map(int, input().split())
c = [list(map(int, input().split())) for i in range(N)]
a = [list(map(int, input().split())) for i in range(h)]
for k in range(N):
    for i in range(N):
        for j in range(N):
            c[i][j] = min(c[i][j], c[i][k] + c[k][j])
s = 0
for i in range(h):
    for j in range(w):
        if a[i][j] >= 0:
            s += c[a[i][j]][1]
print(s)