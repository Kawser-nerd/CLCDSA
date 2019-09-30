from collections import defaultdict
import sys
N,M = map(int,input().split())
d = defaultdict(list)
for i in range(M):
    a,b = map(int,input().split())
    d[a].append(b)
for i in d[1]:
    if N in d[i]:
        print("POSSIBLE")
        sys.exit()
print("IMPOSSIBLE")