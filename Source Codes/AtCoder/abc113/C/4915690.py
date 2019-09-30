# -*- coding: utf-8 -*-
import sys
import copy
from bisect import bisect_left

def main():
	N, M = map(int, input().split(" "))
	data_org = []
	for _ in  range(M):
		p, y = map(int, input().split(" "))
		data_org.append((y, p))
		
	data_tmp = copy.copy(data_org)
	data_tmp.sort()
	
	counts = [0 for _ in range(N)]
	ans = []
	for i, val in enumerate(data_tmp):
		y, p = val
		p_zero = str(p).zfill(6)
		no = counts[p-1] + 1
		no_zero = str(no).zfill(6)
		counts[p-1] += 1
		
		ans.append(p_zero + no_zero)
		
	for i, val in enumerate(data_org):
		y, p = val
		tmp = bisect_left(data_tmp, (y, p))
		print(ans[tmp])
	
	
if __name__ == "__main__":
	main()