'''
Created on May 23, 2010

@author: Mickalot

Input

The first line of the input gives the number of test cases, T.
T test cases follow. Each one starts with a line containing the
dimensions of the bark grid, M and N. N will always be a
multiple of 4. The next M lines will each contain an (N/4)-character
hexadecimal integer, representing a row of the bark grid.
The binary representation of these integers will give you a
strings of N bits, one for each row. Zeros represent black
squares; ones represent white squares of the grid. The rows 
are given in the input from top to bottom. In each row, the 
most-significant bit of the hexadecimal integer corresponds
to the leftmost cell in that row.

Output

For each test case, output one line containing "Case #x: K",
where x is the case number (starting from 1) and K is the
number of different chess board sizes that you can cut out 
by following the procedure described above. The next K lines 
should contain two integers each -- the size of the chess
board (from largest to smallest) and the number of chess 
boards of that size that you can cut out.
'''


def SolveCase(case_index, f):
	ch_to_bark_map = {'0': [0,0,0,0],
						'1': [0,0,0,1],
						'2': [0,0,1,0],
						'3': [0,0,1,1],
						'4': [0,1,0,0],
						'5': [0,1,0,1],
						'6': [0,1,1,0],
						'7': [0,1,1,1],
						'8': [1,0,0,0],
						'9': [1,0,0,1],
						'A': [1,0,1,0],
						'B': [1,0,1,1],
						'C': [1,1,0,0],
						'D': [1,1,0,1],
						'E': [1,1,1,0],
						'F': [1,1,1,1]}
	def text_to_bark(s):
		result = []
		for ch in s:
			result += ch_to_bark_map.get(ch,[])
		return result
						    
	rows, cols = map(int, f.readline().split())
	bark = [text_to_bark(f.readline().strip()) for row in xrange(rows)]
	
	REMOVED = 5
	cut_squares = []
	while True:
		size_to_cut = []
		for row in xrange(rows):
			size_to_cut.append([(bark[row][col] < REMOVED) and 1 or 0 for col in xrange(cols)])
		max_square = 1
		
		# Figure out max square for the cuts
		while True:
			found_bigger = False
			for row in xrange(rows - max_square):
				for col in xrange(cols - max_square):
					if not (size_to_cut[row][col] == max_square): continue
					if not (size_to_cut[row][col+1] == max_square): continue
					if not (size_to_cut[row+1][col] == max_square): continue
					if not (size_to_cut[row+1][col+1] == max_square): continue
					if not (bark[row][col] + bark[row][col+1] + bark[row+1][col] + bark[row+1][col+1] == 2): continue
					if not (bark[row][col] == bark[row+1][col+1]): continue
					if not (bark[row+1][col] == bark[row][col+1]): continue
					size_to_cut[row][col] = max_square+1
					found_bigger = True
			if found_bigger:
				max_square = max_square+1
			else:
				break
		
		#print "Max size", max_square
		
		# Print the bark
		#for row in size_to_cut:
		#	print "".join(map(str, row))
		
		# Do the cuts
		max_square_count = 0
		for row in xrange(rows):
			for col in xrange(cols):
				if size_to_cut[row][col] == max_square:
					overlap = False
					for i in xrange(max_square):
						for j in xrange(max_square):
							if bark[row+i][col+j] == REMOVED:
								overlap = True
					if not overlap:
						max_square_count += 1
						for i in xrange(max_square):
							for j in xrange(max_square):
								size_to_cut[row+i][col+j] = 0
								bark[row+i][col+j] = REMOVED
							
		if max_square_count:
			cut_squares.append((max_square, max_square_count))
		
		if max_square == 1: break
	
	print "Case #%d: %d" % (case_index, len(cut_squares))
	
	for size, count in cut_squares:
		print size, count
	
	for row in xrange(rows):
		for col in xrange(cols):
			if not (bark[row][col] == REMOVED):
				print "Didn't use all from case %d: %d x %d" % (case_index, rows, cols)
				raise "Oh noes!"
	
	if not (sum(x*x*y for x,y in cut_squares) == rows * cols):
		for size, count in cut_squares:
			print size*size*count, size, count
		print "Case %d: %d x %d" % (case_index, rows, cols)
		raise "Oh noes!"
	
	


def Solve(f):
	num_cases = int(f.readline())
	for case_index in xrange(1, num_cases + 1):
		SolveCase(case_index, f)


if __name__ == '__main__':
	#Solve(open("C-test.in"))
	#Solve(open("C-small-attempt1.in"))
	Solve(open("C-large.in"))
	