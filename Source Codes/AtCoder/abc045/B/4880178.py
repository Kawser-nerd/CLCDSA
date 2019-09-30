A = input()
B = input()
C = input()

win = ''
turn = 'A'
while win=='':
	if turn=='A':
		if A=='':
			win = 'A'
		turn = A[:1].upper()
		A = A[1:]
	if turn=='B':
		if B=='':
			win = 'B'
		turn = B[:1].upper()
		B = B[1:]
	if turn=='C':
		if C=='':
			win = 'C'
		turn = C[:1].upper()
		C = C[1:]

print(win)