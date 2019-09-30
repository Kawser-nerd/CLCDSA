#f = file("test3.in", "r")
f = file("/Users/finn/Downloads/C-small-attempt0.in", "r")
#f = file("/Users/finn/Downloads/C-small-attempt1.in", "r")
#f = file("/Users/finn/Downloads/C-small-attempt2.in", "r")
#f = file("/Users/finn/Downloads/C-large.in", "r")
of = file("C-small.out", "w")
#of = file("C-large.out", "w")
lines = f.readlines()

cases = int(lines[0])
line = 1
for case in range(cases):
	input = lines[line].split(" ");
	m = int(input[0])
	n = int(input[1])
	line += 1
	
	board = []
	
	for i in range(m):
		l = lines[line].strip()
		line += 1
		
		row = []
		for j in range(n / 4):
			a = None
			if i % 2 == 0:
				if l[j] == "0": a = [1, 0, 1, 0]
				elif l[j] == "1": a = [1, 0, 1, 1]
				elif l[j] == "2": a = [1, 0, 0, 0]
				elif l[j] == "3": a = [1, 0, 0, 1]
				elif l[j] == "4": a = [1, 1, 1, 0]
				elif l[j] == "5": a = [1, 1, 1, 1]
				elif l[j] == "6": a = [1, 1, 0, 0]
				elif l[j] == "7": a = [1, 1, 0, 1]
				elif l[j] == "8": a = [0, 0, 1, 0]
				elif l[j] == "9": a = [0, 0, 1, 1]
				elif l[j] == "A": a = [0, 0, 0, 0]
				elif l[j] == "B": a = [0, 0, 0, 1]
				elif l[j] == "C": a = [0, 1, 1, 0]
				elif l[j] == "D": a = [0, 1, 1, 1]
				elif l[j] == "E": a = [0, 1, 0, 0]
				elif l[j] == "F": a = [0, 1, 0, 1]
			else:
				if l[j] == "0": a = [0, 1, 0, 1]
				elif l[j] == "1": a = [0, 1, 0, 0]
				elif l[j] == "2": a = [0, 1, 1, 1]
				elif l[j] == "3": a = [0, 1, 1, 0]
				elif l[j] == "4": a = [0, 0, 0, 1]
				elif l[j] == "5": a = [0, 0, 0, 0]
				elif l[j] == "6": a = [0, 0, 1, 1]
				elif l[j] == "7": a = [0, 0, 1, 0]
				elif l[j] == "8": a = [1, 1, 0, 1]
				elif l[j] == "9": a = [1, 1, 0, 0]
				elif l[j] == "A": a = [1, 1, 1, 1]
				elif l[j] == "B": a = [1, 1, 1, 0]
				elif l[j] == "C": a = [1, 0, 0, 1]
				elif l[j] == "D": a = [1, 0, 0, 0]
				elif l[j] == "E": a = [1, 0, 1, 1]
				elif l[j] == "F": a = [1, 0, 1, 0]
						
			row += a
		
		board.append(row)
		
	print "case", case			
	for b in board:
		print b
	
	found = True
	result = []	
	while found:
		row = 0
		col = 0
		last_sz = 0	
		for i in range(m):
			for j in range(n):
				c = board[i][j]
				sz = 0
				ok = True
				while ok and i + sz < m and j + sz < n:
					for ii in range(sz + 1):
						if board[i + sz][j + ii] == 2:
							ok = False
						elif board[i + sz][j + ii] != c:
							ok = False
						elif board[i + ii][j + sz] != c:
							ok = False
							
					if ok:
						sz += 1
						
				if sz > last_sz:
					last_sz = sz
					row = i
					col = j	
	
		#print last_sz, row, col
		if last_sz == 0:
			found = False
		else:
			while len(result) <= last_sz:
				result.append(0)
				
			result[last_sz] += 1
		
			for i in range(last_sz):
				for j in range(last_sz):
					board[row + i][col + j] = 2
	
	print result
	
	diff = 0
	for a in result:
		if a > 0:
			diff += 1
	of.write("Case #%d: %d\n" % (case + 1, diff))
	idx = len(result) - 1
	while idx > 0:
		if result[idx] > 0:
			of.write("%d %d\n" % (idx, result[idx]))
		idx -= 1