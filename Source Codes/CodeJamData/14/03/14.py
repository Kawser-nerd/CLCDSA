import sys

def main():
	f = open(sys.argv[1])
	T = int(f.readline().strip())
	for i in range(1,T+1):
		(R, C, M) = f.readline().strip().split()
		R = int(R)
		C = int(C)
		M = int(M)
		E = R*C-M # Opposite of M
		print "Case #%d:" % i
		if canPass(R,C,E):
			printGrid(R,C,E)
		else:
			print "Impossible"

def printGrid(R,C,E):
	if R == 1:
		print "c" + "."*(E-1) + "*"*(C-E)
		return
	# Now we can assume R >= 2
	# First one or two rows expand across as much as possible (keep equal length)
	if E == 1:
		print "c" + "*"*(C-1)
		rowsFilled = 1
		E = 0
	else:
		# Top two rows must be the same length
		if C == 1: # 1D
			el = 1
		elif E == 2*C+1: # Don't leave E = 1 after this
			el = C-1
		elif E >= 2*C: # Full and not dangling
			el = C
		elif E % 2 == 1:
			el = E/2 - 1
		else:
			el = E/2
		
		print "c" + "."*(el-1) + "*"*(C-el)
		print "."*el + "*"*(C-el)
		rowsFilled = 2
		E -= 2*el
		
	while rowsFilled < R:
		# Empty rows
		if E > C:
			if C == 1:
				el = 1
			elif E-C == 1:
				el = C-1
			else:
				el = C
			print "."*el + "*"*(C-el)
			E -= el
		else:
			# Final rows with empties or full row
			print "."*E + "*"*(C-E)
			E = 0;
		rowsFilled += 1

def canPass(R,C,E):
	if E < 1: # All mines
		return False
	elif E == 1: # Only one free
		return True
	elif R == 1 or C == 1: # One dimensional
		return True
	elif (R == 2 or C == 2) and E % 2: # Two dimensional and odd
		return False
	elif E < 4: # Cannot form a square
		return False
	elif E == 5 or E == 7: # Odd and not enough to wrap to a new line
		return False
	else:
		return True

if __name__ == '__main__':
	main()