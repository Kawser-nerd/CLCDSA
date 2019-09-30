N, W = [int(_) for _ in input().split()]
WV = [[int(_) for _ in input().split()] for i in range(N)]

from collections import defaultdict
from itertools import accumulate

cs = defaultdict(list)

for w, v in WV:
    cs[w].append(v)

minw = min(cs.keys())

for k in range(minw, minw+4):
    cs[k] = [0] + list(accumulate(sorted(cs[k], reverse=True)))

result = 0

for w0, t0 in enumerate(cs[minw]):
    for w1, t1 in enumerate(cs[minw+1]):
        tw1 = w0 * minw + w1 * (minw+1)
        tv1 = t0 + t1
        if tw1 > W:
            break
        for w2, t2 in enumerate(cs[minw+2]):
            tw2 = tw1 + w2 * (minw+2)
            tv2 = tv1 + t2
            if tw2 > W:
                break
            for w3, t3 in enumerate(cs[minw+3]):
                tw3 = tw2 + w3 * (minw+3)
                tv3 = tv2 + t3
                if tw3 > W:
                    break
                result = max(result, tv3)

print(result)