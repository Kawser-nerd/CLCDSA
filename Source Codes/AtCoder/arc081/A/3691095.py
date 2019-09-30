from collections import defaultdict
edge = defaultdict(lambda: 0)
def inpl(): return [int(i) for i in input().split()]
N = int(input())
A = inpl()
for i in A:
    edge[i] += 1
doubled = []
for j,k in edge.items():
    if k >= 2:
        doubled.append(j)
    if k >= 4:
        doubled.append(j)
doubled = (sorted(doubled))
if len(doubled) < 2:
    print(0)
else:
    print(doubled[-1]*doubled[-2])