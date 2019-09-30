for _ in range(int(input())):
	x, y = input().split()
	x = list(x)
	y = int(y)
	
	cnt = 0
	for i in range(len(x)-y+1):
		if x[i]=='-':
			for j in range(i, i+y):
				if x[j] == '-': x[j] = '+'
				else: x[j] = '-'
			cnt += 1
	
	for i in x:
		if i == '-':
			cnt = -1 
	
	if cnt != -1: print ("Case #%d: %d"%(_+1, cnt))
	else: print ("Case #%d: IMPOSSIBLE"%(_+1))
	