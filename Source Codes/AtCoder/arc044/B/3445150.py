N=int(input())
A=[int(i) for i in input().split()]
if A[0]!=0:
    print(0)
    exit()
P=10**9+7
B=[0 for i in range(N)]
for i in range(N):
    B[A[i]]+=1
if B[0]!=1:
    print(0)
    exit()
C=[]
for i in range(N):
    if B[i]!=0:
        C.append(B[i])
    else:
        break
if sum(C)!=N:
    print(0)
    exit()
ans=1
M=len(C)
def npmodm(n,m,p):
    if P<10:
        return (n**p)%m
    else:
        S=bin(p)
        K = len(S)-2
        Q = [0 for i in range(K)]
        for i in range(K):
            Q[i]=int(S[K+1-i])
        R = [n for i in range(K)]
        md = n
        if p%2==0:
            md = 1
        for i in range(1,K):
            R[i] = (R[i-1]**2) % m
            if Q[i] == 1:
                md = (md * R[i]) % m
        return md
twomod=[0 for i in range(N+1)]
twomod[0]=1
for i in range(N):
    twomod[i+1]=(twomod[i]*2)%P
def twoexpnmodp(n):
    if n<=N:
        return twomod[n]
    return npmodm(2,P,n)
for i in range(1,M+1):
    ans*=twoexpnmodp((C[i-1]*(C[i-1]-1))//2)
    ans%=P
    if i==M:
        continue
    ans*=npmodm((twoexpnmodp(C[i-1])-1),P,C[i])
    ans%=P
print(ans)