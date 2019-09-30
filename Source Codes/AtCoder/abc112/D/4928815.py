from math import sqrt
N,M=map(int, input().split())
tmp=int(sqrt(M))
ma=1
for i in range(1, tmp+1):
    if not M % i:
        div = M//i
        ma = max(i if i*N <= M else 0, ma, div if div*N <= M else 0)
print(ma)