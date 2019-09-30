n_testcases = int(input().strip())

import math
from fractions import Fraction


for testcase_n in range(1, n_testcases+1):
    n, p = tuple(int(x) for x in input().split())
    r = list(int(x) for x in input().split())
    q = list()
    for i in range(n):
        q.append(list(Fraction(int(x), r[i]) for x in input().split()))
        q[-1].sort()

    indexes = list(p-1 for _ in range(n))
    res = 0
    while all(idx >= 0 for idx in indexes):
        #print("indexes: " + " ".join("%d" % indexes[i] for i in range(n)))
        #print("weights: " + " ".join("%g" % q[i][indexes[i]] for i in range(n)))
        max_idx = list(sorted(range(n), key=lambda i: q[i][indexes[i]]))[-1]
        min_idx = list(sorted(range(n), key=lambda i: -q[i][indexes[i]]))[-1]
        #print(max_idx)
        #print(min_idx)
        portions = math.ceil(q[max_idx][indexes[max_idx]] / Fraction(11, 10))
        if Fraction(9, 10) * portions <= q[max_idx][indexes[max_idx]] <= Fraction(11, 10) * portions \
                and Fraction(9, 10) * portions <= q[min_idx][indexes[min_idx]] <= Fraction(11, 10) * portions:
            for i in range(n):
                indexes[i] -= 1
            res += 1
        else:
            indexes[max_idx] -= 1
    print("Case #%d: %d" % (testcase_n, res))
