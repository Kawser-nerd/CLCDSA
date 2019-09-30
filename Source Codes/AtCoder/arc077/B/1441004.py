MOD = 10**9 + 7

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


n = int(input())
temp = [None]*(n+2)

for i,a in enumerate(map(int,input().split())):
  if temp[a-1] is None:
    temp[a-1] = i
  else:
    m = n - i + temp[a-1]
    break


b = 1
for i in range(2,m+1):
  b *= i
  b %= MOD

a = b
for i in range(m+1, n+2):
  a *= i
  a %= MOD

ik = modinv(a,MOD)

for i in reversed(range(n+2)):
  temp[i] = ik
  ik *= i
  ik %= MOD


# C(n+1,k) - C(m,k-1)
# C(n,k) = n!/(k!(n-k)!)

for k in range(1, m+2):
  s = a*temp[k]*temp[n+1-k]
  t = b*temp[k-1]*temp[m+1-k]
  print((s-t)%MOD)

for k in range(m+2,n+2):
  s = a*temp[k]*temp[n+1-k]
  print(s%MOD)