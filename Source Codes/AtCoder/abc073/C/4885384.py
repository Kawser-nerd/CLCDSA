from collections import defaultdict
n = int(input())
d = defaultdict(int)

for _ in range(n):
  d[int(input())] += 1

count = 0
for v in d.values():
  if v % 2 != 0:
    count += 1
print(count)