from collections import defaultdict
import sys
def inpl(): return [int(i) for i in input().split()]
H, W, N = inpl()
if not N:
    print(H)
    sys.exit()
A = []
B = defaultdict(lambda: [])
C = defaultdict(lambda: H+1)
for _ in range(N):
    x, y = inpl()
    A.append((x,y))
    B[y].append(x)
T = [0]*(W+1)
T[1] = 2
for i in range(1,W):
    if not B[i+1]:
        T[i+1] = T[i] + 1
        continue
    ctr = T[i]
    while True:
        if ctr in B[i+1]:
            ctr += 1
            continue
        break
    T[i+1] = min(ctr+1, H+1)
for x,y in A:
    if x >= T[y]:
        C[y] = min(C[y], x)
print(min([i-1 for i in C.values()]+[H]))