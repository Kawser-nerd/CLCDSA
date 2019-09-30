#!/usr/bin/env python3

import sys
def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return
ints = get_ints()

def get_floats():
	for line in sys.stdin:
		for word in line.split():
			yield float(word)
	return
floats = get_floats()

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K

def compare(p1, p2):
	(q,a,c)=p1
	(w,b,d)=p2
	x= a*d-b*c
	#print (a,c,b,d,x)
	if x == 0:
		x = q-w
	return x


T = next(ints)
for t in range(T):
	def solve():
		N = next(ints)
		pairs = (N)*[None]
		for i in range(N):
			pairs[i]=[i,next(ints)]
		for i in range(N):
			pairs[i].append(next(ints))
		print(*[i[0] for i in sorted(pairs, key=cmp_to_key(compare))])

	
	print("Case #",t+1,": ",sep='',end='')
	solve()
