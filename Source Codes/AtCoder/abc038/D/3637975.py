# BIT ?? LIS ?? ??????
from bisect import bisect_left

BIG_NUM = 10**9

n = int(input())
wh = [list(map(int, input().split(" "))) for _ in range(n)]

wh.sort(key=lambda x: (x[1], -x[0]))

l = [BIG_NUM]*n
for w_i, h_i in wh:
	l[bisect_left(l, w_i)] = w_i

# print(l)

print(bisect_left(l, BIG_NUM))