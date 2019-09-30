from itertools import combinations
N = int(input())
v = [tuple(map(int, input().split())) for _ in range(N)]
ans = 0
for (x1, y1), (x2, y2), (x3, y3) in combinations(v,3):
    s = abs((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))
    if s > 0 and s%2 == 0:
        ans += 1
print(ans)