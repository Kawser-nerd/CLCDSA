# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

def io_generator():
	return input()

#+++++++++++++++++++

def bbs(v):
	s = [int(ci) for ci in list(str(v))]
	return sum(s)
	
def main(io):
	n, a, b = map(int, io().split())
	return sum([x for x in range(1,n+1) if a<= bbs(x) and bbs(x) <= b])

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))