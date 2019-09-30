from collections import defaultdict

N, K = map(int, input().split())
As = map(int, input().split())

counts = defaultdict(int)
for a in As:
    counts[a] += 1

counts = sorted(counts.values())

if len(counts) <= K:
    print(0)
else:
    total = 0
    for i in range(len(counts) - K):
        total += counts[i]
    print(total)