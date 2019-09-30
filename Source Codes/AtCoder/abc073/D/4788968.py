import sys
import numpy as np
from scipy.sparse.csgraph import floyd_warshall
from itertools import permutations

def main():
    input = sys.stdin.readline
    N, M, R = map(int, input().split())
    r = list(map(int, input().split()))

    INF = float('inf')
    A = [[INF for _ in range(N)] for _ in range(N)]
    for _ in range(M):
        a, b, c = map(int, input().split())
        A[a-1][b-1] = c
        A[b-1][a-1] = c

    G = floyd_warshall(np.array(A))

    ans = INF
    for root in permutations(r):
        cur = 0
        for i in range(R-1):
            s, g = root[i] -1, root[i+1] - 1
            cur += G[s][g]

        ans = min(ans, cur)

    return int(ans)


if __name__ == '__main__':
    print(main())