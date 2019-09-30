N, W = [int(_) for _ in input().split()]
WV = [[int(_) for _ in input().split()] for i in range(N)]

def solve(N, W, WV):
    if N == 0:
        return 0
    if W == 0:
        return 0

from collections import defaultdict
from itertools import accumulate

cs = defaultdict(list)

for w, v in WV:
    cs[w].append(v)

minw = min(cs.keys())

for k in range(minw, minw+4):
    cs[k] = [0] + list(accumulate(sorted(cs[k], reverse=True)))

ts = defaultdict(int)

result = solve(N, W, WV)
result = 0

for w1, t1 in enumerate(cs[minw]):
    for w2, t2 in enumerate(cs[minw+1]):
        tw2 = w1 * minw + w2 * (minw+1)
        tv2 = t1 + t2
        if tw2 > W:
            break
        for w3, t3 in enumerate(cs[minw+2]):
            tw3 = tw2 + w3 * (minw+2)
            tv3 = tv2 + t3
            if tw3 > W:
                break
            for w4, t4 in enumerate(cs[minw+3]):
                tw4 = tw3 + w4 * (minw+3)
                tv4 = tv3 + t4
                # print(w1, w2, w3, w4, tv4)
                if tw4 > W:
                    break
                result = max(result, tv4)

print(result)