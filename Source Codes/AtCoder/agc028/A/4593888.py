n, m = list(map(int, input().split()))
s = input()
t = input()

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

g = gcd(n, m)
l = n*m//g
nn = n//g
mm = m//g

for i in range(g):
  if s[i*nn] != t[i*mm]:
    print(-1)
    exit()
print(l)