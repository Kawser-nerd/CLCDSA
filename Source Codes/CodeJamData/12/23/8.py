from itertools import *
from collections import *

def solve(xs):
    ss = defaultdict(list)
    for n in range(1, 500):
        for cc in combinations(xs, n):
            T = sum(cc)
            ss[T].append(set(cc))
            if len(ss[T]) == 2:
                s, t = ss[T]
                return (' '.join(map(str, s-t)) + '\n' +
                        ' '.join(map(str, t-s)))
    return 'Impossible'

for t in range(1, 1+int(raw_input())):
    print 'Case #%d:\n%s' % (t, solve(map(int, raw_input().split()[1:])))
