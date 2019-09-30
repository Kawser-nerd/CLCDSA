from collections import defaultdict
from itertools import accumulate

n, m = map(int, input().split())
aa = list(map(int, input().split()))
counter = defaultdict(list)

cum = [0] * (m + 2)
ans_1 = 0
for a, b in zip(aa, aa[1:]):
    counter[b].append(a)
    cum[a + 1] += 1
    cum[b] += -1
    if a > b:
        cum[1] += 1
        ans_1 += b
    else:
        ans_1 += b - a

cum = list(accumulate(cum))

ans_prev = ans_1
ans_min = ans_1
for x in range(1, m):
    ans_x = ans_prev
    if x in counter:
        ans_x += sum((x - a) % m - 1 for a in counter[x])
    ans_x -= cum[x]
    ans_min = min(ans_min, ans_x)
    ans_prev = ans_x
print(ans_min)