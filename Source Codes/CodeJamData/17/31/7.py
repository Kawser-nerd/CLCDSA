import functools
import math

import sys

sys.setrecursionlimit(5000)

def f(pancakes, k):

    # print(len(pancakes))
    @functools.lru_cache(maxsize = None)
    def recurse(index, left):
        if left == 0:
            return 0
        if index == len(pancakes):
            return -(10 ** 50)

        case1 = recurse(index + 1, left)
        case2 = 2 * pancakes[index][0] * pancakes[index][1] + recurse(index+1, left - 1)
        if left == k:
            case2 += pancakes[index][0] ** 2

        return max((case1, case2))

    return math.pi * recurse(0, k)
    


T = int(input())
for case in range(1, T+1):
    n,k = map(int, input().split())
    pancakes = []
    for i in range(n):
        pancakes.append(list(map(int, input().split())))
    pancakes = list(reversed(sorted(pancakes)))
    ans = f(pancakes,k)
    print("Case #%s: %s" % (case, ans))

