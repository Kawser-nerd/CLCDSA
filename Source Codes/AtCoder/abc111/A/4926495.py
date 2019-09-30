# -*- coding: utf-8 -*-
import sys
import copy
from bisect import bisect_left

def main():
	N = list(input())
	
	ans = ""
	for i in range(len(N)):
		if N[i] == "1":
			ans += "9"
		else:
			ans += "1"
			
	print(ans)
	
		
	
	
if __name__ == "__main__":
	main()