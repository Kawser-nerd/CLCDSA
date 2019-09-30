#!/usr/bin/env python3
import sys

def ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return

get_int = ints()

T = next(get_int)
for t in range(T):
	N = next(get_int)
	S = next(get_int)
	p = next(get_int)
	total = 0
	for i in range(N):
		val = next(get_int)
		if val > 3*p - 3: total = total+1
		elif val > 3*p - 5 and S > 0 and val > 0:
			total = total + 1
			S = S - 1
	print("Case #",t+1,": ",total,sep='')
