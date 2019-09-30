import math
N = math.factorial(int(input()))
ans = 1
M = 10**9+7
cnt = 1
for i in range(2,1001):
  while N%i == 0:
    cnt += 1
    N = N//i
  ans = ans*cnt
  i += 1
  cnt = 1
print(ans%M)