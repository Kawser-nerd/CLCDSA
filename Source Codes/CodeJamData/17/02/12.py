#!python3

def solve(n):
	digits = []
	while n:
		digits.append(n%10)
		n //= 10
	digits = list(reversed(digits))

	ans = None
	for i in range(len(digits)):
		if i and digits[i] < digits[i-1]:
			break
		if i == 0 or digits[i]-1 >= digits[i-1]:
			if digits[i]-1 == 0:
				ans = [9]*(len(digits)-1)
			else:
				ans = digits[:i]+[digits[i]-1]+[9]*(len(digits)-i-1)
			# print(ans)
		if i == len(digits)-1:
			ans = digits
			# print(digits)

	return ''.join(map(str, ans))

def main():
	ntest = int(input())
	for i in range(ntest):
		n = int(input())
		ans = solve(n)
		print("Case #%d: %s" % (i+1, ans))

if __name__ == '__main__':
	main()
	# solve(132)
	# solve(1000)
	# solve(7)
	# solve(111111110)