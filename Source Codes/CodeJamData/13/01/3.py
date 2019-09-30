def bingo(a, c):
	for i in range(4):
		flag = True
		for j in range(4):
			if a[i][j] != c and a[i][j] != 'T':
				flag = False
		if flag:
			return True
	
	for i in range(4):
		flag = True
		for j in range(4):
			if a[j][i] != c and a[j][i] != 'T':
				flag = False
		if flag:
			return True
	
	flag = True
	for i in range(4):
		if a[i][i] != c and a[i][i] != 'T':
			flag = False
	if flag:
		return True
	
	flag = True
	for i in range(4):
		if a[i][3-i] != c and a[i][3-i] != 'T':
			flag = False
	if flag:
		return True
	
	return False
	
def finished(a):
	for i in range(4):
		for j in range(4):
			if a[i][j] == '.':
				return False
	return True

def func(a):
	if bingo(a, 'O'):
		return "O won"
	if bingo(a, 'X'):
		return "X won"
	if finished(a):
		return "Draw"
	return "Game has not completed"

T = int(raw_input())
for t in range(T):
	a = []
	for i in range(4):
		s = raw_input()
		a.append(s)
	print "Case #" + str(t+1) + ":", func(a)
	if t != T-1:
		raw_input()
