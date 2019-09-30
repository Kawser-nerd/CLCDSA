N,M = map(int,input().split())

if N==M:
  ans = 1
  for i in range(1,N+1):
    ans *= i
    ans %= 10**9 + 7
  ans *= ans
  ans %= 10**9 + 7
  ans *= 2
  ans %= 10**9 + 7
elif N==M+1 or N+1==M:
  ans = 1
  for i in range(1,N+1):
    ans *= i
    ans %= 10**9 + 7
  for i in range(1,M+1):
    ans *= i
    ans %= 10**9 + 7
else:
  ans = 0
print(ans)