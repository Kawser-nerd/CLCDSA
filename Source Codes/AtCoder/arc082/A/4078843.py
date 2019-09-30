import collections

n = int(input())
a = list(map(int, input().split()))

counter = collections.defaultdict(int)
for b in a:
    counter[b - 1] += 1
    counter[b] += 1
    counter[b + 1] += 1

print(max(counter.values()))