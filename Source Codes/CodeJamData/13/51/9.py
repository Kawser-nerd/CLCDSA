#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

# Best obtainable score by completely filling `level`, and partially filling `level+1`
def best_level_score(level, numbers, money):
    base_cost = 0
    base_gain = 0
    width = 0
    for n in numbers:
        if n <= level:
            base_cost += level - n
            width += 1
    if base_cost > money:
        return 0

    if width == 0:
        return 0

    base_gain = base_cost
    base_score = base_gain * (36 / width) - base_cost

    scores = [base_score]
    for n in reversed(numbers):
        if n <= level:
            base_cost += 1
            if base_cost > money:
                break
            width -= 1
            if width == 0:
                break
            base_gain -= (level - n)
            score = base_gain * (36 / width) - base_cost
            scores.append(score)
    return max(scores)





fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    B, N = map(int, fin.readline().split())
    numbers = list(map(int, fin.readline().split())) + [0] * (37 - N)
    numbers.sort()

    scores = []
    # This would be brute-force, O(max(numbers))
    # for i in range(max(numbers) + 1):
    #     score = best_level_score(i, numbers, B)
    #     scores.append(score)

    # This doesn't seem to be important, but we include them for safety
    for n in numbers:
        scores.append(best_level_score(n, numbers, B))
        if n > 0:
            scores.append(best_level_score(n - 1, numbers, B))

    width = 0
    underwater = 0
    for n in numbers:
        if width > 0:
            fill = (B + underwater) // width
            # These two don't seem to have an effect, but we include them for safety
            scores.append(best_level_score(fill, numbers, B))
            scores.append(best_level_score(fill+1, numbers, B))

            # This is the important one
            if fill > 0:
                scores.append(best_level_score(fill-1, numbers, B))
        width += 1
        underwater += n

    result = max(scores)

    print("Case #%d: %.10f" % (case, result))

