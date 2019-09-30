N,M=map(int,input().split())
f=[int(input()) for i in range(N)]
mod=1000000007

#N=10000
#M=N
#f=list(range(1,N+1))

LIST=[-1 for i in range(N)]
NOW=[-1]*(M+1)

for i in range(N):
    x=f[i]
    if NOW[x]!=-1:
        LIST[i]=NOW[x]
    NOW[x]=i
    #print(LIST)

#print(LIST)

for i in range(1,N):
    if LIST[i]<=LIST[i-1]:
        LIST[i]=LIST[i-1]

#print(LIST)

DP=[0]*(N+2)
SUM=[0]*(N+2)

DP[1]=1
#print(DP,SUM)

def dp(i):
    SUM[i]=(DP[i-1]+SUM[i-1])%mod
    DP[i]=(SUM[i]-SUM[LIST[i-2]+2])%mod

for i in range(2,N+2):
    dp(i)
    #print(DP,SUM)
print(DP[N+1])