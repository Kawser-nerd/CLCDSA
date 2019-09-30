from collections import defaultdict
def inpl(): return [int(i) for i in input().split()]

HW = defaultdict(lambda: 0)
direction = [(0,0),(1,1),(1,0),(1,-1),(0,-1),(-1,-1),(-1,0),(-1,1),(0,1)]

H, W, N = inpl()
for _ in range(N):
    a, b = inpl()
    for dh, dw in direction:
        if 2 <= a+dh <= H-1 and 2 <= b+dw <= W-1: 
            HW[(a+dh, b+dw)] += 1

ans = [0 for i in range(10)]
print((H-2)*(W-2) - len(HW))
for j in HW.values():
    ans[j] += 1
for i in ans[1:]:
    print(i)