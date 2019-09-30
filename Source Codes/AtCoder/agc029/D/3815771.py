H, W, N = map(int, input().split())
posObss = [{H} for y in range(W)]
for _ in range(N):
    X, Y = map(int, input().split())
    posObss[Y - 1].add(X - 1)

ans = H
xNow = 0
for y in range(W):
    xLim = min([x for x in posObss[y] if x > xNow])
    ans = min(ans, xLim)

    if y == W - 1: break
    xNow += 1
    while xNow in posObss[y + 1]:
        xNow += 1
    if xNow >= xLim: break

print(ans)