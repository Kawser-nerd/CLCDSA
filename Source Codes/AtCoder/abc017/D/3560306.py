n,m = map(int,input().split())
mod = 1000000007
a = [int(input())for i in range(n)]
dp = [0]*(n+1)
dp[0] = 1
b = [0] * n
migi = 0
hida = 1
yo = set()
while migi < n:
  yo.add(a[migi])
  try:
    b[hida] = migi
  except:
    pass
  if hida == migi:
    hida +=1
  if hida < n and (a[hida] not in yo):
    yo.add(a[hida])
    b[hida] = migi
    hida += 1
  else:
    yo.remove(a[migi])
    migi += 1
c = [0] *n
SUM = 1
hida = 0
for i in range(1,n+1):
  for j in range(hida,b[i-1]):
    SUM += (mod-dp[j]%mod)
  hida = b[i-1]
  dp[i] += SUM%mod
  SUM += dp[i]
  SUM %=mod
print(dp[-1]%mod)