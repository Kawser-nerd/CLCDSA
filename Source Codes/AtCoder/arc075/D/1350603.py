def solve(d, K):
  r = 1
  for k in range(K,1,-2):
    if d >= 10**k:
      return 0
    t = (-d)%10
    d = abs((d-t*(10**(k-1)-1))//10)
    r *= 10-t-(K==k)
  return r*(10**(K%2)) if d == 0 else 0

D = int(input())
result = 0
l = len(str(D))
for k in range(l,2*l+1):
  result += solve(D, k)

print(result)