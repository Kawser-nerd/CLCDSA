def main():
	n = int(input())
	xi, yi, hi = [0]*n, [0]*n, [0]*n
	stack = []
	result = []
	for i in range(n):
		xi[i], yi[i], hi[i] = map(int, input().split())
		if hi[i] > 0:
			stack = [xi[i], yi[i], hi[i]]
	for i in range(101):
		for j in range(101):
			guess = stack[2] + abs(stack[0]-i) + abs(stack[1]-j)
			is_result = True
			for k in range(n):
				result = guess - abs(xi[k]-i) - abs(yi[k]-j)
				result = max(result, 0)
				if hi[k] != result:
					is_result = False
					break
			if is_result:
				print(str(i)+" "+str(j)+" "+str(guess))
				return


if __name__ == '__main__':
    main()