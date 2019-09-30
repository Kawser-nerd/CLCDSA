T = input()

def check(b):
	for i in range(4):
		row = ''.join(sorted(b[i]))
		if row == 'TXXX' or row == 'OOOT' or row == 'XXXX' or row == 'OOOO':
			return row[2] + ' won'

	for i in range(4):
		row = ''.join(sorted([b[j][i] for j in range(4)]))
		if row == 'TXXX' or row == 'OOOT' or row == 'XXXX' or row == 'OOOO':
			return row[2] + ' won'


	row = ''.join(sorted([b[i][i] for i in range(4)]))	
	if row == 'TXXX' or row == 'OOOT' or row == 'XXXX' or row == 'OOOO':
		return row[2] + ' won'

	row = ''.join(sorted([b[i][3-i] for i in range(4)]))	
	if row == 'TXXX' or row == 'OOOT' or row == 'XXXX' or row == 'OOOO':
		return row[2] + ' won'

	for i in range(4):
		for j in range(4):
			if b[i][j] == '.':
				return 'Game has not completed'

	return 'Draw'

for case in range(T):
	board = []
	for i in range(4):
		x = raw_input()
		board.append([c for c in x.strip()])
	#print board
	blank = raw_input()


	s = check(board)

	print "Case #%d: %s" % (case + 1, s)