def main():
	K = int(input())
	odd = (K // 2) + 1 if K %2 == 1 else (K//2)
	even = K // 2
	print(odd*even)


if __name__ == '__main__':
    main()