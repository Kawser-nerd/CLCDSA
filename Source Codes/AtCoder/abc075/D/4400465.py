def acc2(grid):
    H = len(grid); W = len(grid[0])
    for i in range(H):
        for j in range(W-1):
            grid[i][j+1] += grid[i][j]
    for j in range(W):
        for i in range(H-1):
            grid[i+1][j] += grid[i][j]
    ngrid = [[0]*(W+1)]
    for i in range(H):
        line = [0] + grid[i]
        ngrid.append(line)
    return ngrid

from bisect import bisect_left
N,K = map(int,input().split())
X = []; Y = []; info = []
for i in range(N):
    x,y = map(int,input().split())
    X.append(x); Y.append(y); info.append([x,y])
X.sort(); Y.sort()

acc = [[0]*(N) for i in range(N)]
for x, y in info:
    j = bisect_left(X,x)
    i = bisect_left(Y,y)
    acc[i][j] += 1

acc = acc2(acc)

ans = float('inf')
for t in range(N-1):
    for b in range(t+1,N):
        for l in range(N-1):
            for r in range(l+1,N):
                num = acc[b+1][r+1] - acc[b+1][l] - acc[t][r+1] + acc[t][l]
                if num < K: continue
                S = (Y[b] - Y[t]) * (X[r] - X[l])
                if S < ans:
                    ans = S

print(ans)