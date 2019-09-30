def main():
	n, m = map(int, input().split())

	total = m//n
	answer = 1
	for i in range(1, total+1):
		if i * i > m:
			break

		if m % i == 0:
			answer = max(i, answer)
			if i >= n:
				answer = max(m//i, answer)

	print(answer)


if __name__ == '__main__':
    main()