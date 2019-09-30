import bisect
from collections import defaultdict

N = int(input())
As  = sorted(map(int, input().split()))
Bs  = sorted(map(int, input().split()))
Cs  = sorted(map(int, input().split()))

b_counts = []
for b in Bs[::-1]:
    count = len(Cs) - bisect.bisect(Cs, b)
    if len(b_counts) > 0:
        count += b_counts[-1]
    b_counts.append(count)
b_counts = b_counts[::-1]

total = 0
for a in As:
    i = bisect.bisect(Bs, a)
    if i >= len(Bs):
        continue
    total += b_counts[i]

print(total)