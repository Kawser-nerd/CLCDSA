n, x = map(int, input().split())
M = []
for i in range(n):
  M.append(int(input()))
ans = n
x -= sum(M)
ans += x//min(M)
print(ans)