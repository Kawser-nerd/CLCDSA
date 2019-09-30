import itertools

import math

def score(stack):
    syrup = math.pi * max(x[0] for x in stack)**2

    for item in stack:
        syrup += 2*math.pi*item[0]*item[1]

    return syrup


def ring_score(item):
    return 2*math.pi*item[0]*item[1]


def solve(pancakes, k):
    return max(itertools.combinations(pancakes, k), key=score)

"""
x = [(1, 10), (2, 9), (3, 8), (4, 7), (5, 6), (6, 5), (7, 4), (8, 3), (9, 2), (10, 1)]
r = solve(x, 5)
print(r, score(r))
"""

with open('A-large.in') as infile:
    with open('A-large.out', 'w') as outfile:
        cases = int(next(infile))

        for case in range(1, cases+1):
            n, k = map(int, next(infile).split())
            pancakes = []

            for _ in range(n):
                pancakes.append(tuple(map(int, next(infile).split())))

            pancakes.sort(key=ring_score, reverse=True)
            preliminary = pancakes[:k]
            remaining = pancakes[k:]

            curr_score = score(preliminary)

            if remaining:
                other_score = score(preliminary[:-1] + [max(remaining)])

                if other_score > curr_score:
                    curr_score = other_score

            print(case, curr_score)
            print("Case #{}: {}".format(case, curr_score), file=outfile)
