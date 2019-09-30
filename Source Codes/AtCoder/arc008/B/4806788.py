N, M = [int(_) for _ in input().split()]
name = input()
kit = input()

from collections import Counter
import math

def solve(name, kit):
    ns = Counter(name)
    ks = Counter(kit)
    result = 0
    for n in ns:
        if not n in ks:
            return -1
        result = max(result, math.ceil(ns[n] / ks[n]))
    return result

print(solve(name, kit))