N = int(input())
red = []
for _ in range(N):
    a, b = map(int, input().split())
    red.append((b, a))
red.sort()
blue = []
for _ in range(N):
    c, d = map(int, input().split())
    blue.append((c, d))
blue.sort()
ans = 0
for c, d in blue:
    for i in range(N - 1, -1, -1):
        if red[i][1] < c and red[i][0] < d:
            ans += 1
            red[i] = (300, 300)
            break
print(ans)