'''
Created on May 23, 2010

@author: Mickalot

Input

The first line of the input gives the number of test cases, T. T test cases follow.
Each case begins with a line containing an integer N, denoting the number of wires you see.

The next N lines each describe one wire with two integers Ai and Bi.
These describe the windows that this wire connects: Ai is the height
of the window on the left building, and Bi is the height of the window
on the right building.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of intersection points you see.

Limits

1 <= T <= 15.
1 <= Ai <= 104.
1 <= Bi <= 104.
Within each test case, all Ai are different.
Within each test case, all Bi are different.
No three wires intersect at the same point.


'''

def SolveCase(case_index, f):
	num_wires = int(f.readline())
	h1_to_wireindex = {}
	h2_to_wireindex = {}
	for wire_index in xrange(num_wires):
		h1, h2 = map(int, f.readline().split())
		h1_to_wireindex[h1] = wire_index
		h2_to_wireindex[h2] = wire_index
	h1s = h1_to_wireindex.keys()
	h2s = h2_to_wireindex.keys()
	h1s.sort()
	h2s.sort()
	
	wireindex_to_h1index = {}
	wireindex_to_h2index = {}
	for heightindex, height in enumerate(h1s):
		w = h1_to_wireindex[height]
		wireindex_to_h1index[w] = heightindex
	for heightindex, height in enumerate(h2s):
		w = h2_to_wireindex[height]
		wireindex_to_h2index[w] = heightindex
		
	num_crossings = 0
	for wireindex in xrange(num_wires):
		h1index = wireindex_to_h1index[wireindex]
		h2index = wireindex_to_h2index[wireindex]
		if h2index > h1index:
			num_crossings += h2index - h1index
	print "Case #%d: %d" % (case_index, num_crossings)
	

def Solve(f):
	num_cases = int(f.readline())
	for case_index in xrange(1, num_cases + 1):
		SolveCase(case_index, f)


if __name__ == '__main__':
	#Solve(open("A-test.in"))
	Solve(open("A-small-attempt0.in"))
	#Solve("A-large.in")
	