from collections import defaultdict

N = int(input())
As = map(int, input().split())

counts = defaultdict(int)
for a in As:
    counts[a-1] += 1
    counts[a] += 1
    counts[a+1] += 1

print(max(counts.values()))