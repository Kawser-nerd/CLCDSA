def inpl(): return [int(i) for i in input().split()]
N, M = inpl()
print(2**M*(1800*M +100*N))