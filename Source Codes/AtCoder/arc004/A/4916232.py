from math import sqrt
n = int(input())
a = [list(map(int, input().split()))for _ in range(n)]
ans = 0
for p1 in a:
  for p2 in a:
    ans = max(ans, abs(p1[0]-p2[0])**2+abs(p1[1]-p2[1])**2)
print(sqrt(ans))