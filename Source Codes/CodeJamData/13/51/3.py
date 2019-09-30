def reader(inFile):
    [B,N] = inFile.getInts()
    xs = inFile.getInts()
    return (B,xs)

from sys import stderr
from fractions import Fraction

def func(xs, k, amt):
    tot = 0
    for i in xrange(37):
        if i < k:
            tot += amt - xs[i]
        elif xs[i] <= amt:
            tot += (amt + 1) - xs[i]
    return tot

def winnings(xs, k, amt):
    tot = 0
    for i in xrange(k):
        tot += 36 * (amt - xs[i])
    return Fraction(tot, k) - func(xs, k, amt)

def solver((B,xs)):
    xs = [0] * (37 - len(xs)) + xs
    xs.sort()
    rec = 0
    for k in xrange(1,37):
        toEqual = func(xs, k, xs[k-1])
        if toEqual > B:
            continue
        # can spend toEqual + k * t
        # if t > 0, expected win is 36 * (xs[k-1] + t)
        # obv want to maximize t
        can = xs[k-1]
        cant = xs[k-1] + B + 1
        while can + 1 < cant:
            mid = (can + cant) / 2
            cost = func(xs, k, mid)
            if cost <= B:
                can = mid
            else:
                cant = mid
        if can > xs[k-1]:
            rec = max(winnings(xs, k, can), rec)
        rec = max(winnings(xs, k, xs[k-1]), rec)
    # one more case
    if xs[35] < xs[36]:
        toEqual = func(xs, 36, xs[36] - 1)
        if toEqual <= B:
            rec = max(winnings(xs, 36, xs[36] - 1), rec)
    return str(int(rec))+("%.6f"%(rec - int(rec)))[1:]

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_3/a/", "a").run()
