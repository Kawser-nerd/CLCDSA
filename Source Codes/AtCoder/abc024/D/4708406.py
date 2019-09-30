mod = 10**9 + 7

def powmod(x, n):
  ret = 1
  while n > 0:
    if n & 1:
      ret *= x; ret %= mod; n -= 1
    else:
      x *= x; x %= mod; n >>= 1
  return ret
  
def rev(n):
  return powmod(n, mod-2)
    
A = int(input())
B = int(input())
C = int(input())
n = A * rev(C) % mod
m = B * rev(C) % mod
c = (1-n) % mod * m % mod * rev((n + n*m - m) % mod) % mod
r = (m + m * c - 1) % mod
print(r, c)