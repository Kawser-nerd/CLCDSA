# -*- coding: utf-8 -*-
import sys

def main():
	N = int(input())
	A = input().split(" ")
	A = [int(s) for s in A]
	
	maps = [0] * (len(A))
	for i, val in enumerate(A):
		maps[i] = maps[i-1] + val
		
	maps.append(0)
	counts = {}
	for i, val in enumerate(maps):
		if val in counts:
			counts[val] += 1
		else:
			counts[val] = 1
	
	ans = 0
	#print(maps)
	for key, val in counts.items():
		if val == 1:
			continue
		for i in range(val-1, 0, -1):
			ans += i
	
	print(ans)
	
	
if __name__ == "__main__":
	main()