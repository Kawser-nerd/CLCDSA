from collections import defaultdict

MOD = 1000000007
iist = lambda: map(int,input().split())

N,M = iist()
Q = defaultdict(list)
for i in range(M):
  l,r,x = iist()
  Q[r].append((l,x-1))

if any(x != 0 for l,x in Q[1]):
  print(0)
  exit(0)

dp = {(0,0):3}
memo = [6]
s = 3

for pk in range(1,N):
  k = pk+1

  for i,c in enumerate(memo):
    c %= MOD
    dp[i,pk] = c
    memo[i] *= 2
    memo[i] %= MOD

  memo.append(2*s%MOD)
  s = 3*s%MOD
  subQ = Q[k]

  for i,j in list(dp.keys()):
    for l,x in subQ:
      if x != (l<=i)+(l<=j):
        c = dp[i,j]
        memo[i] -= c
        memo[j] -= c
        s -= c
        del dp[i,j]
        break

  s %= MOD

print(s)