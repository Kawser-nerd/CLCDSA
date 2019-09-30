# -*- coding: utf-8 -*-
import sys
import copy
from bisect import bisect_left

def main():
	N = int(input())
	
	for i in range(N, 1000):
		tmp = i % 10
		ans = ""
		tugi = 0
		isOK = True
		for j in range(len(str(i))):
			if j == 0:
				tugi = i
			tmp2 = tugi % 10
			tugi = tugi // 10
			ans += str(tmp)
			if tmp != tmp2:
				isOK = False
				break
		if isOK == True:
			print(ans)
			sys.exit()
		
	
if __name__ == "__main__":
	main()