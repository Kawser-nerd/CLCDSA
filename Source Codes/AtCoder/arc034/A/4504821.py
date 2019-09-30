n = int(input())
ans = 0
for i in range(n):
  a, b, c, d, e = map(int, input().split())
  ans=max(ans, a+b+c+d+110*e/900)
print(ans)