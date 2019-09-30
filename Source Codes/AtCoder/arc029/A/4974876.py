N = int(input())
t = []
for _ in range(N):
  t.append(int(input()))
ans = 200
for bit in range(2**N):
  ans1, ans2 = 0, 0
  for i in range(N):
    if bit & (1<<i):
      ans1 += t[i]
    else:
      ans2 += t[i]
  ans = min(ans, max(ans1, ans2))
print(ans)