P=10**9+7
N=int(input())
t=sorted([int(input()) for i in range(N)])
S=[0 for i in range(N+1)]
for i in range(N):
    S[i+1]=S[i]+t[i]
Fact=[0 for i in range(N+1)]
Fact[0]=1
for i in range(N):
    Fact[i+1]=((i+1)*Fact[i])%P
D=dict()
for i in range(N):
    if t[i] in D:
        D[t[i]]+=1
    else:
        D[t[i]]=1
print(sum(S))
ans=1
for k in D:
    m=D[k]
    ans*=Fact[m]
    ans%=P
print(ans)