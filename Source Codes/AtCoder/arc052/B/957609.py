N,Q = map(int,input().split())
X = [0]*N
R = [0]*N
H = [0]*N
V = [0]*N
for i in range(N):
    X[i],R[i],H[i] = map(int,input().split())
    V[i] = (H[i]*R[i]*R[i]*3.14159265)/3
for i in range(Q):
    A,B = map(int,input().split())
    s = 0
    for j in range(N):
        a = H[j] - (min((X[j]+H[j],max((A,X[j])))) - X[j])
        b = H[j] - (max((X[j],min((B,H[j]+X[j])))) - X[j])
        aH = a/H[j]
        bH = b/H[j]
        ans = V[j]*(aH - bH)*( aH**2 + aH*bH + bH**2 )
        s += ans
    print(s)