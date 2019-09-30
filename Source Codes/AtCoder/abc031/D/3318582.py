import sys
from itertools import product

K, N = map(int, input().split())
q = [(list(map(lambda x: int(x)-1, v)), w, len(w)) for v, w in map(lambda l: l.split(), sys.stdin)]

for length_list in product(range(1, 4), repeat=K):
    for v, w, l in q:
        if sum(length_list[n] for n in v) != l:
            break
    else:
        ans = [""]*K
        for v, w, l in q:
            for n in v:
                ans[n] = w[:length_list[n]]
                w = w[length_list[n]:]
        print(*ans, sep="\n")
        break