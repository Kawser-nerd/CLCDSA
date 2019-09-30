N = int(input())
points = [[int(i) for i in input().split()] for i in range(N)]
ans = 0
for x, y, in points:
    for dx, dy in points:
        ans = max(ans, ((x - dx)**2 + (y - dy)**2)**0.5)
print(ans)