def inpl(): return [int(i) for i in input().split()]
N, M = inpl()
a = (2*N+M)//4
print(min(a,M//2))