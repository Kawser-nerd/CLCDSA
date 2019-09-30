import sys
from collections import defaultdict

_in = open(sys.argv[1])
def raw(): return _in.readline().rstrip('\n')
def ints(): return map(int, raw().split())
raw_input = raw # we all forget sometimes
L = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
M = [
    ("G", 8, "EIGHT"),
    ("W", 2, "TWO"),
    ("Z", 0, "ZERO"),
    ("X", 6, "SIX"),
    ("U", 4, "FOUR"),
    ("S", 7, "SEVEN"),
    ("V", 5, "FIVE"),
    ("O", 1, "ONE"),
    ("T", 3, "THREE"),
    ("I", 9, "NINE")
]

def solve(S):
    count = defaultdict(int)
    ret = []
    for c in S:
        count[c] += 1
    for c, x, word in M:
        n = count[c]
        for d in word:
            count[d] -= n
        ret += [x] * n
    ret.sort()
    return ''.join(map(str, ret))

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        S = raw()
        print "Case #{}: {}".format(case_num, solve(S))
