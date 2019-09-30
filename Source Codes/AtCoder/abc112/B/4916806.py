# -*- coding: utf-8 -*-
import sys
import copy
from bisect import bisect_left

def main():
	N, T = map(int, input().split(" "))
	CT = []
	isOK = False
	for _ in range(N):
		c, t = map(int, input().split(" "))
		if t <= T:
			isOK = True
			CT.append((c, t))
	
	if isOK == False:
		print("TLE")
		sys.exit()
	
	CT.sort()
	c, t = CT[0]
	print(c)
	
	
if __name__ == "__main__":
	main()