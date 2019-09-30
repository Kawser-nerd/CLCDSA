N, M = map(int,input().split())
ball = [1 for i in range(N)]
boolball = [False for i in range(N)]
boolball[0] = True
for _ in range(M):
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    if boolball[x]:
        boolball[y] = True
    if ball[x] == 1:
        boolball[x] = False
    ball[x] -= 1
    ball[y] += 1

ans = 0
for t in boolball:
    if t:
        ans += 1

print(ans)