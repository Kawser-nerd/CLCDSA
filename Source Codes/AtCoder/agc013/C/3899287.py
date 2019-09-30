import sys
def input(): return sys.stdin.readline()
def inpl(): return [int(i) for i in input().split()]

N, L, T = inpl()
Ant = []
ctr = 0
for _ in range(N):
    X, W = inpl()
    Ant.append((X + T*(3-2*W))%L)
    ctr += (X + T*(3-2*W))//L
Ant.sort()
ctr %= N
ans = Ant[ctr:] + Ant[:ctr]
for i in ans:
    print(i)