N,X = map(int,input().split())
x = list(map(int,input().split()))
for i in range(N):
  x[i] = abs(X-x[i])
x.sort()

def gcd(a,b):
  if a < b:
    temp = a
    a = b
    b = temp
  if b == 0: return a
  return (gcd(b,a%b))

import functools
ans = functools.reduce(gcd,x)
print(ans)