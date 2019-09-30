def main():
	N = int(input())
	current = N
	ans = ""
	while current != 0:
		if current % 2 == 0:
			ans = "0" + ans
		else:
			ans = "1" + ans
			current -= 1
		current //= -2

	if ans == "":
		ans = "0"

	print(ans)


if __name__ == '__main__':
    main()