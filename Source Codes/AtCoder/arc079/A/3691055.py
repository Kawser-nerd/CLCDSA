from collections import defaultdict
Liner = defaultdict(lambda: [])
def inpl(): return [int(i) for i in input().split()]
import sys
N, M = inpl()
for _ in range(M):
    a, b = inpl()
    Liner[a].append(b)
    Liner[b].append(a)
if not Liner[1]:
    print('IMPOSSIBLE')
    sys.exit()
for i in Liner[1]:
    if N in Liner[i]:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')