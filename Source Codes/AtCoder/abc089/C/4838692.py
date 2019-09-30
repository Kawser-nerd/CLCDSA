from itertools import combinations
from numpy import prod

N = int(input())
S = [input() for _ in range(N)]

first_chars = {'M': 0, 'A': 0, 'R': 0, 'C': 0, 'H': 0}
for s in S:
    if s[0] in first_chars.keys():
        first_chars[s[0]] += 1

combs = list(combinations([v for v in first_chars.values() if v > 0], 3))
print(sum([prod(comb) for comb in combs]))