from collections import defaultdict

N = int(input())
As = map(int, input().split())

counts = defaultdict(int)
for a in As:
    counts[a] += 1

total = 0
for n, c in counts.items():
    if n < c:
        total += c - n
    elif n > c:
        total += c

print(total)