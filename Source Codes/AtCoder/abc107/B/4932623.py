def main():
	H, W = map(int, input().split())
	a = [["." for _ in range(W)] for _ in range(H)]
	ans = []
	is_column_white = [True]*H
	is_row_white = [True]*W
	for i in range(H):
		row = input()
		for j in range(W):
			a[i][j] = row[j]
			if row[j] == "#":
				is_column_white[i]=False
				is_row_white[j] = False

	for i in range(H):
		if is_column_white[i]:
			continue
		ans_row = ""
		for j in range(W):
			if is_row_white[j]:
				continue
			ans_row += a[i][j]
		print(ans_row)

if __name__ == '__main__':
    main()