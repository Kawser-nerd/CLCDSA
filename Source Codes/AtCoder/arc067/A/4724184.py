N=int(input())
comp=[0 for i in range(N+1)]

for n in range(1,N+1):
    for i in range(2,N+1):
        while n%i==0:
            comp[i]+=1
            n//=i
        if n==1:
            break
MOD=10**9+7
res=1
for c in comp:
    res*=c+1
    res%=MOD
print(res)