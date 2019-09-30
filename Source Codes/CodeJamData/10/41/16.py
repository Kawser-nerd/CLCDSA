'''
Created on June 5, 2010

@author: Mickalot

Problem

'''


	

def SolveCase(case_index, infile, outfile):
	k = int(infile.readline())
	size = 2*k-1
	center = k-1
	
	buffer = size*" "
	diamond = []
	for i in xrange(size):
		line = (infile.readline().rstrip() + buffer)[:size]
		diamond.append([ch in '0123456789' and ch or None for ch in line])
	
	
	def GetDiamond(x, y):
		if x < 0 or x >= size: return None
		if y < 0 or y >= size: return None
		return diamond[x][y]
	
	def IsSymmetricalAround(x, y):
		x_max = min(x, (2*k-2) - x) + 1
		y_max = min(y, (2*k-2) - y) + 1
		
		for x_offset in xrange(size):
			for y_offset in xrange(size):
				item = GetDiamond(x-x_offset, y-y_offset)
				
				next = GetDiamond(x-x_offset, y+y_offset)
				if next:
					if item and item != next: return False
					item = next
					
				next = GetDiamond(x+x_offset, y-y_offset)
				if next:
					if item and item != next: return False
					item = next
					
				next = GetDiamond(x+x_offset, y+y_offset)
				if next:
					if item and item != next: return False
					item = next
		return True
	
	cost = ((2*k) ** 2) - (k**2)
	found = False
	for extra_k in xrange(size):
		for i in xrange(-extra_k, extra_k+1):
			j = extra_k - abs(i)
			if IsSymmetricalAround(center+i, center-j) or j and IsSymmetricalAround(center+i, center+j):
				cost = (k+extra_k)**2 - k*k
				print "Size %d is symmetrical at %d, %d (%d => %d - %d)" % (k, i, j, extra_k, (k+extra_k)**2, k**2)
				found = True
				break
		
		if found: break
	
	if not found: print "No match, defaulting to %d - %d" % ((2*k) ** 2, k**2)
	message = "Case #%d: %d\n" % (case_index, cost)
	print message,
	outfile.write(message)


def Solve(filename):
	infile = open(filename)
	outfile = open(filename + ".out", "w")
	num_cases = int(infile.readline())
	for case_index in xrange(1, num_cases + 1):
		SolveCase(case_index, infile, outfile)
		outfile.flush()


if __name__ == '__main__':
	#Solve("A-test.in")
	Solve("A-small-attempt3.in.in")
	#Solve("A-large.in")
	