

#fp = open('A-large-practice.in', 'r')
fp = open('A-large.in', 'r')
#fp = open('input', 'r')
n = int(fp.next())

case = 1

for line in fp:
	
	n = int(line)
	
	l = []
	tab = []
	
	wp = [0] * n
	owp = [0] * n
	oowp = [0] * n
	
	for x in range(n):
		line = fp.next().strip()
		
		tab.append(line)
		l.append([0.,0.,0.])
		
		for c in line:
			if c == '1':
				l[-1][0] += 1
				l[-1][1] += 1
			if c == '0':
				l[-1][0] += 1
				l[-1][2] += 1
		
		wp[x] = l[-1][1] / l[-1][0]
	
	for x in range(n):
		total = 0.0
		div = 0
		
		for y in range(n):
			if tab[x][y] == '.' or x == y:
				continue
			
			#if x == 3:
			#	print '>>', y
			
			div += 1
			
			won = 0.
			games = 0.
			
			for z in range(n):
				if z == x:
					continue
				if tab[y][z] != '.':
					games += 1
				if tab[y][z] == '1':
					won += 1
					
			total += (won / games)
			
			#if x == 3:
			#	print '>>', won, games, total
			
		owp[x] = total / div

	for x in range(n):
		total = 0.0
		div = 0
		
		for y in range(n):
			if tab[x][y] == '.' or x == y:
				continue
			
			div += 1
			total += owp[y]
			
		oowp[x] = total / div
	
	#print wp
	#print owp
	#print oowp
	
	print 'Case #' + str(case) + ':'
	
	for x in range(n):
		print 0.25 * wp[x] + 0.5 * owp[x] + 0.25 * oowp[x]
	
	case += 1

	#break
	
