n,m,*A=map(int,open(0).read().split())
D=[0]*(2*m+2)
cur = 0
S = 0
for a,b in zip(A,A[1:]):
    S += (b-a)%m
    b += m*(b<a)
    k = b-a
    if k>1:
        D[a+2] += 1
        D[b+1] -= k
        D[b+2] += k-1
for i in range(1,2*m+2):
    D[i]+=D[i-1]
for i in range(1,2*m+2):
    D[i]+=D[i-1]
print(S-max(D[a]+D[a+m]for a in A))