#!/usr/bin/env python
import fileinput

def main():
    reader = fileinput.input()
    trials = int(reader.next())
    for t in range(1, trials+1):
        result = trial(reader)
        print "Case #%d: %s" % (t, result)

def ints(reader):
    return [int(k) for k in reader.next().strip().split()]

def trial(reader):
    n, k, b, t = ints(reader)
    x = ints(reader)
    v = ints(reader)
    times = [0] * len(x)
    for i in range(len(x)):
        times[i] = (b - x[i]) / float(v[i]) - t
    ok, n = swaps(times, k)
    return n if ok else 'IMPOSSIBLE'

def swaps(times, k):
    if k == 0: return True, 0
    i = lastfinisher(times)
    if i < 0: return False, 0
    cut = times[:i] + times[i+1:]
    ok, n = swaps(cut, k - 1)
    return ok, n + len(times) - i - 1

def lastfinisher(times):
    for i in reversed(range(len(times))):
        if times[i] <= 0: return i
    return -1

main()
