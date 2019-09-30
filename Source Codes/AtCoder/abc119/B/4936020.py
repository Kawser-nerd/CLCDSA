n = int(input())
ans = 0
for i in range(n):
  a, t = input().split()
  if t == 'JPY':
    ans += int(a)
  elif t == 'BTC':
    ans += float(a) * 380000.0
print(ans)