from collections import defaultdict

N, M = map(int, input().split())

import sys

teiki = defaultdict(set)
for i in range(M):
    a, b = map(int, input().split())
    teiki[a].add(b)


if 1 not in teiki:
    print('IMPOSSIBLE')
    sys.exit()

for i in teiki[1]:
    if i in teiki and N in teiki[i]:
        print('POSSIBLE')
        sys.exit()

print('IMPOSSIBLE')