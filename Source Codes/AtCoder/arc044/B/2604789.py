n = int(input())
a = list(map(int, input().split()))

MOD = 10**9 + 7

def solve():
  if a[0] != 0: return 0

  c = [0] * (max(a)+1)
  for ai in a:
    c[ai] += 1

  if c[0] != 1: return 0

  ans = 1
  for i in range(1,len(c)):
    if c[i] == 0: return 0
    ans = (ans*pow(2, c[i]*(c[i]-1)//2, MOD))%MOD
    ans = (ans*(pow((pow(2, c[i-1], MOD)+MOD-1), c[i], MOD)))%MOD

  return ans

print(solve())