# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	a,b,c,d = map(int, io().split())
	
	rets=['Left', 'Balanced', 'Right']
	
	if a+b > c+d:
		return rets[0]
	elif a+b < c+d:
		return rets[2]
	else:
		return rets[1]

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))