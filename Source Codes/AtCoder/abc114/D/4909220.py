def main():
	n = int(input())
	exp_num = [0]*(n+1)

	for i in range(2, n+1):
		cur = i
		for j in range(2, i+1):
			while cur % j == 0:
				exp_num[j] += 1
				cur //= j

	def num(m:int) -> int:
		return len(list(filter(lambda x: x > m-2, exp_num)))

	total = (
		num(75) + num(25)*(num(3)-1)
		 + num(15)*(num(5)-1)
		 + (num(5)*(num(5) - 1)//2)*(num(3)-2)
		 )

	print(total)


if __name__ == '__main__':
    main()