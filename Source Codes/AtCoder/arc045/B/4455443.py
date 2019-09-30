from itertools import accumulate
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int, input().split())
R = [list(map(int, input().split())) for _ in range(M)]


def solve():
    imos = [0]*(N+2)
    ans = []
    for a, b in R:
        imos[a] += 1
        imos[b+1] -= 1
    imos = list(accumulate(imos))
    for i in range(N+2):
        if imos[i] != 1:
            imos[i] = 0
    imos = list(accumulate(imos))
    for i, t in enumerate(R):
        a = t[0]
        b = t[1]
        if imos[b]-imos[a-1] == 0:
            ans.append(i)

    if ans:
        print(len(ans))
        print("\n".join(map(lambda x: str(x+1), ans)))
    else:
        print(0)


solve()