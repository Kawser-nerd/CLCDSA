N = list(map(int, input().split()))

from itertools import combinations

print(sorted([sum(c) for c in list(combinations(N,3))])[-3])