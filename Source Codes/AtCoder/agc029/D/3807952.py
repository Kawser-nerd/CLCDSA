H, W, N = map( int, input().split())
X = [ tuple( map( int, input().split())) for _ in range(N)]
X.sort()
d = 0
ans = H
for i in range(N):
    if X[i][1]+d == X[i][0]:
        d += 1
    if X[i][1] + d < X[i][0]:
        ans = X[i][0]-1
        break
print(ans)