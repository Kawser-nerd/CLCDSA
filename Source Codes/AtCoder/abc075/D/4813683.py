n, kk = map(int, input().split())
p = [list(map(int, input().split())) for i in range(n)]
x_set = set(i[1] for i in p)
y_set = set(i[0] for i in p)
d_x = {}
d_y = {}
for i, x in enumerate(sorted(list(x_set))):
    d_x[x] = i
for i, y in enumerate(sorted(list(y_set))):
    d_y[y] = i
g_x = {}
g_y = {}
w = len(d_x)
h = len(d_y)
board = [[0]*(w+1) for i in range(h+1)]
tmp = [[0]*h for i in range(w)]
for y, x in p:
    ys = d_y[y]
    xs = d_x[x]
    g_x[xs] = x
    g_y[ys] = y
    tmp[ys][xs] += 1
for i in range(h):
    for j in range(w):
        board[i+1][j+1] = board[i+1][j] + board[i][j+1] - board[i][j] + tmp[i][j]
#for i in board:
#    print(i)
ans = float("inf")
for i in range(h-1):
    for j in range(i+1, h):
        for k in range(w-1):
            for l in range(k+1, w):
                s = board[j+1][l+1] - board[i][l+1] - board[j+1][k] + board[i][k]
                if s >= kk:
                    #print(g_y[j], g_y[i], g_x[l] , g_x[k])
                    area = (g_y[j] - g_y[i]) * (g_x[l] - g_x[k])
                    ans = min(ans, area)
print(ans)