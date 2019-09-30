#!/usr/bin/python

import sys

def enlarge(Box):
	Box[0] = Box[0] -1
	Box[1] = Box[1] -1
	Box[2] = Box[2] +1
	Box[3] = Box[3] +1
	return Box

def supbox(Box):
	return [Box[0] -1, Box[1] -1, Box[2] +1, Box[3] +1]

def intersect(A,B):
	return A[0] <= B[2] and A[2] >= B[0] and A[1] <= B[3] and A[3] >= B[1]

def intersectSet(A, setS):
	for B in setS:
		if intersect(A,B):
			return True
	return False

def overflow(Box):
	return Box[0] < 0

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		W,H,B = map(int, sys.stdin.readline().split())
		#table = (W,H)
		mask = [[W,0,W,H]]
		umask = []
		for i in range(B):
			umask.append(map(int, sys.stdin.readline().split()))

		flow = 0

		#start = 0
		flag = False
		while True:
			#print mask
			for E in mask:
				if overflow(enlarge(E)):
					flag = True
					break
				for F in umask[:]:
					if intersect(E,F):
						mask.append(F)
						umask.remove(F)
			if flag:
				break
			#print mask, umask
			flow = flow+1
			print flow

		print "Case #{}:".format(t+1), flow
