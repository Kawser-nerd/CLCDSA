MAX=501
MOD=100003
dp=[]
c=[]

def cc(n,k):
  k=min(n-k,k)
  nom=1
  denom=1
  for i in range(k):
    nom*=n-i
    denom*=i+1
  return nom/denom

for i in range(MAX):
  dp.append([])
  c.append([])
  for j in range(MAX):
    dp[i].append(-1)
    c[i].append(cc(i,j)%MOD)

def get(n,k):
  if(dp[n][k]!=-1): return dp[n][k]
  if(k>=n): return 0
  if(k==1): return 1
  sum=0
  for i in range(1,k):
    if(k-i>n-k):continue
    sum=(sum+get(k,i)*c[n-k-1][k-i-1])%MOD
  dp[n][k]=sum
  return sum

C=input()
for t in range(C):
  n=input()
  sum=0
  for i in range(1,n): sum=(sum+get(n,i))%MOD
  print "Case #%d: %d"%(t+1,sum)
