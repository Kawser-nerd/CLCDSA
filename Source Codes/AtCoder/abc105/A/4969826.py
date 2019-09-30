def main():
	N, K = map(int, input().split())
	if N % K == 0:
		print(0)
	else:
		print(1)


if __name__ == '__main__':
    main()