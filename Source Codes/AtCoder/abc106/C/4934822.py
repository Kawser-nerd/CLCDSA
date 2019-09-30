def main():
	S = input()
	K = int(input())
	# day = 5*(10**15)
	pos = 1
	for c in S:
		c_int = int(c)
		if c_int > 1:
			print(c)
			break
		if pos == K:
			print(c)
			break
		pos += 1



if __name__ == '__main__':
    main()