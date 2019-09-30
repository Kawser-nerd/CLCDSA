#????????
#??????
#??????Zero-Sum
#?????Zero-Sum-Ranges...
N=int(input())
A=[int(i) for i in input().split()]
S=[0 for i in range(N+1)]
for i in range(N):
    S[i+1]=A[i]+S[i]
D=dict()
for i in range(N+1):
    if S[i] in D:
        D[S[i]]+=1
    else:
        D[S[i]]=1
ans=0
for k in D:
    t=D[k]
    ans+=(t*(t-1))//2
print(ans)