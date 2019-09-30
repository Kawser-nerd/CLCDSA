N, Q = map(int, input().split())
A = [0]*N

for i in range(Q):
    L, R, T = map(int, input().split())
    for i in range(R-L+1):
        A[L-1+i] = T

for a in A:
    print(a)