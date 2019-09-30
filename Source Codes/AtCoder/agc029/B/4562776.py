from bisect import bisect_left, bisect_right
from collections import deque

N = int(input())
A = list(map(int, input().split(" ")))
A.sort()
A = deque(A)
ans = 0
t_max = len(bin(A[-1])) - 2
for t in range(t_max, 0, -1):
    if len(A) < 2: break
    while len(bin(A[-1])) - 2 > t:
        A.pop()
        if len(A) < 2: break
    if len(A) < 2: break
    pow2 = 1 << t
    A_tmp = deque()
    while t == len(bin(A[-1])) - 2:
        r = A.pop()
        idx = bisect_left(A, pow2 - r)
        for _ in range(idx):
            A_tmp.appendleft(A.popleft())
        if len(A) == 0: break
        if A[0] + r == pow2:
            A.popleft()
            ans += 1
        if len(A) < 2: break
    A.extendleft(A_tmp)
                    
print(ans)