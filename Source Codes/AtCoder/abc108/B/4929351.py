def main():
	x1, y1, x2, y2 = map(int, input().split())
	dx = x2 - x1
	dy = y2 - y1
	x3 = x2 - dy
	y3 = y2 + dx
	x4 = x3 - dx
	y4 = y3 - dy

	ans = str(x3) + " " + str(y3) + " " + str(x4) + " " + str(y4)
	print(ans)


if __name__ == '__main__':
    main()