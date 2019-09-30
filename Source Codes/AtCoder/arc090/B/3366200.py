ai = lambda: list(map(int, input().split()))

n,m = ai()
from collections import defaultdict
dd = defaultdict(list)

for _ in range(m):
    l,r,d = ai()
    dd[l].append((r,d))
    dd[r].append((l,-d))

pos = [None] * (n+1)

for i in range(1, n+1):
    if pos[i] is not None:
        continue
    pos[i] = 0
    stack = [i]
    while stack:
        s = stack.pop()
        for p,d in dd[s]:
            if pos[p] is None:
                pos[p] = pos[s] + d
                stack.append(p)
            elif pos[p] != pos[s] + d:
                print('No')
                exit()
print('Yes')