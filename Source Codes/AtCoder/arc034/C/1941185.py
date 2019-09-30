import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor, factorial
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache, reduce
from operator import xor
from heapq import heappush, heappop
INF = float("inf")
sys.setrecursionlimit(10**7)

MOD = 1000000007

# 4????, ?, ?, ??
dy4, dx4 = [0, -1, 0, 1], [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W
def ceil(a, b): return (a + b - 1) // b


# n????????(O(n ^ (1 / 2)))
# primeFactorDecomposition(12): {2: 2, 3: 1}
def prime_factor_decomposition(n):
    import math
    m = defaultdict(int)
    while n > 1:
        find_factor = False
        for i in range(2, int(math.sqrt(n)) + 1):

            if n % i == 0:
                m[i] += 1
                n //= i
                find_factor = True
                break

        if not find_factor:
            m[n] += 1
            break

    return m


def main():
    A, B = map(int, input().split())
    d = defaultdict(int)
    for x in range(B + 1, A + 1):
        m = prime_factor_decomposition(x)
        for k, v in m.items():
            d[k] += v

    ans = 1
    for k, v in d.items():
        ans = (ans * (v + 1)) % MOD
    print(ans)


if __name__ == '__main__':
    main()