n = int(input())
t = [int(input()) for _ in range(n)]

ans = 200
for i in range(1 << n):
  time_a = 0
  time_b = 0
  for j in range(n):
    if i >> j & 1:
      time_a += t[j]
    else:
      time_b += t[j]
  ans = min(ans, max(time_a, time_b))
print(ans)