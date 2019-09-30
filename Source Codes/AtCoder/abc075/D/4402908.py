N,K = map(int, input().split())
xy = []
for _ in range(N):
    xy.append( tuple(map(int, input().split())) )
xs,ys = map(list, zip(*xy))
xs.sort()
ys.sort()
grid = [[0]*(N+1) for _ in range(N+1)] # compressed coordinate
# ????
# ???????1-index?????????????????
for x,y in xy:
    i = xs.index(x)
    j = ys.index(y)
    grid[j+1][i+1] = 1
    
# print(grid)

# 2?????
for h in range(N+1):
    for w in range(1,N+1):
        grid[h][w] += grid[h][w-1]
for w in range(N+1):
    for h in range(1,N+1):
        grid[h][w] += grid[h-1][w]

#print(grid)
ans = float('inf')
for l in range(N):
    for r in range(l+1,N):
        for b in range(N):
            for t in range(b+1,N):
                cnt = grid[t+1][r+1] - grid[b][r+1] - grid[t+1][l] \
                      + grid[b][l]
                xl,xr = xs[l],xs[r]
                yb,yt = ys[b],ys[t]
                if cnt>=K:
                    ans = min(ans, (xr-xl)*(yt-yb))
print(ans)