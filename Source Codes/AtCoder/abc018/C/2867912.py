N = 510
h, w, K = (int(i) for i in input().split())

mp = []
for _ in range(0, h):
    mp.append(input())


cnt = [[0] * N * 3 for _ in range( N * 3 )]

for i in range (0, h):
    for j in range (0, w):
        u = N + i + j
        v = N + j - i
        cnt[u+1][v+1] = 1 if mp[i][j] == 'x' else 0

for i in range(0, 3 * N):
    for j in range(1, 3 * N):
        cnt[i][j] += cnt[i][j-1]

for j in range(0, 3 * N):
    for i in range(1, 3 * N):
        cnt[i][j] += cnt[i-1][j]

def get(x, y, X, Y):
    return cnt[Y][X] - cnt[y][X] - cnt[Y][x] + cnt[y][x];


ans = 0
for i in range (0, h):
    for j in range (0, w):
        if ( i - K + 1 < 0 or j - K + 1 < 0 or i + K - 1 >= h or j + K - 1 >= w):
            continue
        x = j - (K - 1)
        y = i
        X = j + (K - 1)
        Y = i
        u = N + x + y
        v = N + x - y
        U = N + X + Y
        V = N + X - Y
        val = get(v, u, V+1, U+1)
        #print(u <= U, v <= V)
        ans = ans + (1 if val == 0 else 0)

print (ans)