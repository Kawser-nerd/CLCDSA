N = int(input())
S = [input() for i in range(N)]
from collections import defaultdict
d = defaultdict(int)
for i in S:
    d[i] += 1

for i in d.keys():
    if d[i] == max(d.values()):
        print(i)
        exit()