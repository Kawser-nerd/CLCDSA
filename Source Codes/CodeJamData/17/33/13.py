from collections import defaultdict
import sys

cases = int(raw_input())


for c in range(1,cases+1):
	print "Case #" + str(c) + ":",
	n, k = map(int, raw_input().split())
	usable = int(raw_input().replace(".", ""))
	cores = [int(core.replace(".", "")) for core in raw_input().split()]
	while usable > 0:
		lowest = (1000000, -1)
		for i in range(len(cores)):
			if cores[i] < lowest[0]:
				lowest = (cores[i], i)
		usable-=1
		cores[lowest[1]] += 1
	ans = 1.0
	for core in cores:
		ans *= (core/10000.0)
	print ans