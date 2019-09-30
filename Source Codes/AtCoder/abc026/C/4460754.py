# encoding: utf-8
N = int(input())
B = [int(input()) for i in range(1, N)]

child = [[] for i in range(N)]
for i, Bi in enumerate(B):
    child[Bi - 1].append(i + 2)

def integrate(idn):
    if len(child[idn - 1]) < 1: return 1
    Bs = [integrate(i) for i in child[idn - 1]]
    return min(Bs) + max(Bs) + 1

print(integrate(1))