import sys
import numpy as np
import heapq

def solve(n,k):

	intervals = {n:1}
	lens = [-n]

	ls = 0
	rs = 0

	while k > 0:
		val = -heapq.heappop(lens)
		num = intervals[val]
		del intervals[val]

		k = k - num

		ls = int((val - 1) / 2)
		rs = val - ls - 1

		if not ls in intervals:
			intervals[ls] = 0
			heapq.heappush(lens,-ls)
		if not rs in intervals:
			intervals[rs] = 0
			heapq.heappush(lens,-rs)

		intervals[rs] = intervals[rs] + num
		intervals[ls] = intervals[ls] + num
		

	return (max(ls,rs),min(ls,rs))


t = int(raw_input())
for i in range(1, t + 1):
  n, m = [s for s in raw_input().split(" ")] 

  data = [int(a) for a in list(str(n))]

  result = solve(int(n), int(m))

  print("Case #{}: {} {}".format(i, result[0], result[1]))