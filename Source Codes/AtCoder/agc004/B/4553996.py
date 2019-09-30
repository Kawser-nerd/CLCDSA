N, x = map(int, input().split())
A = [int(a) for a in input().split()]
M = [a for a in A]

mi = 10**100
for j in range(N):
    s = 0
    for i in range(N):
        s += M[i]
        
    mi = min(mi, s+x*j)
    M = [min(M[i], A[(i-j-1) % N]) for i in range(N)]

print(mi)