#!/usr/bin/pypy

from random import randint
from math import log
import sys

def read_line():
    s = raw_input()
    while s == "":
        s = raw_input()
    return s

def read_int():
    return int(read_line())

def read_ints():
    return tuple(int(s) for s in read_line().split())

def make_list(N):
    return list(range(N))

def bad_shuffle(N):
    a = make_list(N)
    for k in range(N):
        p = randint(0, N-1)
        a[k], a[p] = a[p], a[k]
    return a

def good_shuffle(N):
    a = make_list(N)
    for k in range(N):
        p = randint(k, N-1)
        a[k], a[p] = a[p], a[k]
    return a

def validate(vals):
    s = set(vals)
    for i in range(len(vals)):
        assert i in s

def memoize(f):
    known = {}
    def g(N):
        if N not in known:
            known[N] = f(N)
        return known[N]
    return g

def score_of(A, B):
    if A == 0 or B == 0:
        return 0
    return log(A / B)

@memoize
def build_classify_probabilities(N):
    TRIES = 100000
    while 1:
        freq_le = [0 for i in range(N)] # The frequency x is at position i <= x
        for i in range(TRIES):
            vals = bad_shuffle(N)
            validate(vals)
            for i, x in enumerate(vals):
                if i <= x:
                    freq_le[x] += 1
        if all(x > 0 for x in freq_le):
            break

    scores = []
    for i in range(N):
        chance_le_good = float(freq_le[i]) / TRIES
        chance_le_bad = float(i+1) / N

        assert 0 <= chance_le_good <= 1
        assert 0 <= chance_le_bad <= 1
        chance_gt_good = 1 - chance_le_good
        chance_gt_bad = 1 - chance_le_bad


        le_score = score_of(chance_le_good, chance_le_bad)
        gt_score = score_of(chance_gt_good, chance_gt_bad)
        sys.stderr.write("{0:.08f} {1:.08f} {2:.08f} {3:.08f}\n".format(chance_le_bad, chance_le_good, le_score, gt_score))
        scores.append((gt_score, le_score))

    return tuple(scores)

@memoize
def choose_cutoff_score(N):
    probs = build_classify_probabilities(N)
    CASES = 10000

    totals = []
    for i in range(CASES):
        # bad shuffles will have higher scores
        s = score_with_probs(good_shuffle(N))
        totals.append((s, 1))
        t = score_with_probs(bad_shuffle(N))
        totals.append((t, -1))
    totals.sort()
    total_right = CASES
    best = (total_right, 0)
    for i, (score, delta) in enumerate(totals):
        total_right += delta
        sys.stderr.write("{0} {1:0.08f} {2:0.08f}\n".format(i, score, total_right))
        best = max(best, (total_right, score))

    best_count, best_cutoff = best
    best_percent = float(best_count) / (CASES * 2)
    sys.stderr.write("best: {0} accuracy={1:0.8f}\n".format(best_cutoff, best_percent))
    return best_cutoff


def score_with_probs(vals):
    validate(vals)
    N = len(vals)
    probs = build_classify_probabilities(N)

    score = 0.0
    for i, x in enumerate(vals):
        le = i <= x
        gt_score, le_score = probs[x]
        score += le_score if le else gt_score
    return score

def classify(vals):
    score = score_with_probs(vals)
    cutoff = choose_cutoff_score(len(vals))

    sys.stderr.write("Score = {0}, cutoff = {1}\n".format(score, cutoff))
    return "BAD" if score > cutoff else "GOOD"

def solve():
    N = read_int()
    perm = read_ints()
    assert len(perm) == N
    return classify(perm)

if __name__ == "__main__":
    T = read_int()
    for i in range(1, T+1):
        solution = solve()
        print "Case #{0}: {1}".format(i, solution)
