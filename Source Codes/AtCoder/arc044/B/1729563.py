from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")
MOD = 10 ** 9 + 7


def main():
    N = int(input())
    A_list = list(map(int, input().split()))

    if A_list[0] != 0 or A_list.count(0) >= 2:
        print(0)
        return

    c = Counter(A_list)
    ans = 1
    pre = 1
    for length in range(1, max(A_list) + 1):
        v = c[length]
        if v == 0:
            print(0)
            return

        ans = (ans * pow(2, (v * (v - 1) // 2), MOD)) % MOD
        ans = (ans * pow(2 ** pre - 1, v, MOD)) % MOD
        pre = v

    print(ans % MOD)


if __name__ == '__main__':
    main()