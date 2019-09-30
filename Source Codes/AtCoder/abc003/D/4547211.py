mod = 10**9 + 7

def powmod(x, n):
  ret = 1
  while n > 0:
    if n & 1:
      ret *= x; ret %= mod; n -= 1
    else:
      x *= x; x %= mod; n >>= 1
  return ret

fact = [1 for _ in range(1000)]
revfact = [1 for _ in range(1000)]

def setfact(n):
  for i in range(n):
    fact[i+1] = fact[i] * (i+1); fact[i+1] %= mod
  revfact[n] = powmod(fact[n], mod-2)
  for i in range(n):
    revfact[n-i-1] = revfact[n-i] * (n-i); revfact[i] %= mod
  return

def getC(n, r):
  if n < r: return 0
  return fact[n] * revfact[r] % mod * revfact[n-r] % mod

r, c = map(int, input().split())
x, y = map(int, input().split())
d, l = map(int, input().split())
setfact(x*y)
num = 0
for i in range(1, 2**4):
  txy = [x, y]
  cnt = 0
  for j in range(4):
    if (i>>j)&1:
      txy[j%2] -= 1
      cnt += 1
  if txy[0] > 0 and txy[1] > 0:
    num += (cnt%2*2-1) * getC(txy[0]*txy[1], d+l) % mod
print((r-x+1) * (c-y+1) % mod * (getC(x*y, d+l) - num) % mod * getC(d+l, d) % mod)