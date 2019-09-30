N=int(input())
a=list(map(int,input().split()))

S=[0]
s = 0
for i in range(N):
    s+=a[i]
    S.append(s)
ans=10**28
for i in range(1,N):
    ans=min(abs(S[N]-2*S[i]),ans)
print(ans)