from collections import defaultdict

MOD = 1000000007
iist = lambda: map(int,input().split())

N,M = iist()
Q = defaultdict(list)
for i in range(M):
  l,r,x = iist()
  Q[r].append((l,x))

if any(x != 1 for l,x in Q[1]):
  print(0)
  exit(0)

dp = defaultdict(int)
dp[0,0] = 3

x_sum = [3]
y_sum = [3]
s = 3

for pk in range(1,N):
  k = pk+1

  for i,(a,b) in enumerate(zip(x_sum,y_sum)):
    c = (a+b)%MOD
    dp[i,pk] = c
    x_sum[i] += c

  x_sum.append(0)
  y_sum.append((2*s)%MOD)
  s *= 3
  subQ = Q[k]

  for i,j in list(dp.keys()):
    for l,x in subQ:
      if x != (l<=i)+(l<=j)+1:
        c = dp[i,j]
        x_sum[i] -= c
        y_sum[j] -= c
        s -= c
        del dp[i,j]
        break

  for i in range(pk):
    x_sum[i] %= MOD
    y_sum[i] %= MOD
  s %= MOD

print(s)