n, d = map(int, input().split())
x, y = map(int, input().split())
f = [0] * (n + 1)
f[0] = 1
for i in range(1, n+1):
  f[i] = f[i-1] * i
v = 0
for i in range(n + 1):
  a, b = i * d - x, (n - i) * d - y
  if a < 0 or b < 0 or a % (2 * d) or b % (2 * d):
    continue
  a //= (2 * d)
  b //= (2 * d)
  v += f[n] // (f[a] * f[i - a] * f[b] * f[n - i - b])
print("%.18f"%(v / 4 ** n))