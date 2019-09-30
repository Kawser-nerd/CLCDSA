N,M=map(int,input().split())
X=[int(x) for x in input().split()]
Y=[int(y) for y in input().split()]
MOD=10**9+7

SX=0
SY=0

for i in range(N):
  SX=(SX+(2*i+1-N)*X[i])%MOD
for j in range(M):
  SY=(SY+(2*j+1-M)*Y[j])%MOD
  
print((SX*SY)%MOD)