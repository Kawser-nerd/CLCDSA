import math
import sys
EPS = 1e-9

def extend(end, amount):
    global heights

    for i in xrange(0, end + 1):
        heights[i] += amount

# returns an int that is definitely more than x
def more(x):
    return int(math.floor(x + 1 + EPS))

def extrapolate(start, mid, end, start_val, mid_val):
    return more(start_val + float(mid_val - start_val) * (end - start) / (mid - start))

# preconditions: start is already solved, end is the very last thing
# must preserve the height at start
def solve(start, end):
    global impossible
    global heights

    for i in xrange(start, end):
        if high[i] > end:
            impossible = True
            return
    
    if start + 1 >= end:
        return
    
    peaks = [start]
    x = start

    while x < end:
        x = high[x]
        peaks.append(x)

    assert(x == end)
    P = len(peaks)
    slope = 0

    for i in xrange(P - 1):
        solve(peaks[i] + 1, peaks[i + 1])

    for i in xrange(P - 1):
        a, b = peaks[i], peaks[i + 1]
        # slope needs to be at most slope, a needs to be able to see b
        a_height = more(heights[b] - slope * (b - a))

        for j in xrange(a + 1, b):
            a_height = max(a_height, extrapolate(b, j, a, heights[b], heights[j]))

        extend(a, a_height - heights[a])
        slope = float(heights[b] - heights[a]) / (b - a)

for test_case in xrange(1, int(raw_input()) + 1):
    sys.setrecursionlimit(1000000)
    N = int(raw_input())
    high = map(int, raw_input().split())
    high = [x - 1 for x in high]
    heights = [0] * N
    impossible = False
    solve(0, N - 1)
    assert(min(heights) >= 0)
    assert(max(heights) <= 10**9)
    print "Case #{0}: {1}".format(test_case, "Impossible" if impossible else ' '.join(map(str, heights)))
