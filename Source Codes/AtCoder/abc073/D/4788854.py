import sys
import numpy as np
from scipy.sparse.csgraph import floyd_warshall
from itertools import permutations


def main():
    input = sys.stdin.readline
    N, M, R = map(int, input().split())
    r = list(map(int, input().split()))

    INF = 10**9
    A = [[INF for _ in range(N)] for _ in range(N)]
    for _ in range(M):
        a, b, c = map(int, input().split())
        A[a-1][b-1] = c
        A[b-1][a-1] = c

    D = np.array(A, dtype=int)
    G = floyd_warshall(D)

    """
    ans = INF
    for start in r[:2]:
        passed = [start]
        temp_ans = 0
        while len(passed) < len(r):
            cur = INF
            next_start = -1
            for dest in r:
                if dest in passed:
                    continue

                if A[start-1][dest-1] < cur:
                    next_start = dest
                    cur = A[start-1][dest-1]

            passed.append(next_start)
            start = next_start
            temp_ans += cur

        ans = min(ans, temp_ans)
    """

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