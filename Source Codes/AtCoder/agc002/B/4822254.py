N, M = map(int, input().split())
red = [False for i in range(N+1)]
red[1] = True
box = [1 for i in range(N+1)]

for i in range(M):
    x, y = map(int, input().split())
    if red[x]:
        red[y] = True
    box[x] -= 1
    box[y] += 1
    if box[x] == 0:
        red[x] = False

ans = 0
for i in range(1, N+1):
    if red[i] and box[i] > 0:
        ans += 1
print(ans)