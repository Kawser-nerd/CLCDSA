def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a%b)

n, x = map(int, input().split())
print(3*(n - gcd(n, x)))