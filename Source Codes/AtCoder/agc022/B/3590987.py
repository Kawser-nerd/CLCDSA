# -*- coding: utf-8 -*-
from sys import stdin

d_in = lambda: int(stdin.readline())  # N = d_in()


MAX = 30000
N = d_in()

base = [3, 25, 2, 35, 55]
cand = []
for i in range(4, MAX // 2, 2):
    cand.append(i)
    cand.append(MAX - i)

for i in range(9, MAX // 2, 6):
    cand.append(i)
    cand.append(MAX - i)

ans = []
if N < 5:
    ans.extend(base[:3])
    if N == 4:
        ans.append(MAX)
elif N % 2 == 1:
    ans.extend(base)
    ans.extend(cand[:N-5])
else:
    ans.extend(base)
    ans.append(MAX)
    ans.extend(cand[:N-6])
print(*ans)