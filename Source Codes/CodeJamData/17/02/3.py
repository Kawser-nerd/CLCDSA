from __future__ import print_function
import sys
from sys import stdin


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def ln(f=int):
	return list(map(f,stdin.readline().strip().split()))

T, = ln()
INF = float('inf')

for test in range(T):
	s, = ln(str)
	s = list(map(int,list(s)))

	prev=9
	res = ""
	ind = None
	for i in range(1,len(s)):
		if s[i] < s[i-1]:
			ind = i
			# res = "9"*len(s[i:])
			# s = s[:i]
			break

	if ind != None:
		for i in range(ind+1,len(s)):
			s[i] = 9

		while ind != 0 and s[ind] < s[ind-1]:
			s[ind-1] -= 1
			s[ind] = 9
			ind -= 1
		
	res = int("".join(list(map(str,s))))

	print ("Case #" + str(test+1) + ": " + str(res))


