'''
4321
3999

45623
45599

3399

099


'''

def solve_n(n):
	digits = map(int, str(n))
	return solve(digits)

def solve(digits):
	
	for i in range(len(digits)-1):
		a = digits[i]
		b = digits[i+1]
		if a > b:
			assert digits[i] > 0
			
			digits[i] -= 1
			for j in range(i+1,len(digits)):
				digits[j] = 9
			
			return solve(digits)
	
	return int(''.join(map(str,digits)))

	
case_count = input()
for i in range(1,case_count+1):
	n = input()
	print 'Case #%d: %s' % (i, solve_n(n))