N = int(input())

def fun(n,x):
  i = 0
  while(n > 0):
    i += n % x
    n //= x
  return i

ans = N

for j in range(N+1):
  ans = min(ans,fun(j,6)+fun(N-j,9))
print(ans)