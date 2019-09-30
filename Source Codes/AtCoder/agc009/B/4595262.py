import sys
sys.setrecursionlimit(2*10**5)
N = int(input())
A = [int(input()) for _ in range(N-1)]
if len(set(A)) == N - 1:
    print(N - 1)
    sys.exit()
H = [[] for _ in range(N+1)]
for i, a in enumerate(A, 2):
    H[a].append(i)

def depth(x):
    if not H[x]:
        return 0
    k = len(H[x])
    return max([k - i + j for i, j in zip(range(k), sorted([depth(x) for x in H[x]]))])

print(depth(1))