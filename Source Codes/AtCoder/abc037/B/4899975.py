N,Q = map(int,input().split())
Aa = [0]*N
for i in range(Q):
    L,R,T = map(int,input().split())
    for j in range(L-1,R):
        Aa[j]=T
for a in Aa:
    print(a)