def dfs(map, start):
	start_row = start[0]
	start_column = start[1]
	map[start_row][start_column] = 0
	# 4 square search
	if start_row != 0 and map[start_row - 1][start_column] == 1:
		map = dfs(map, [start_row - 1, start_column])
	if start_row != 9 and map[start_row + 1][start_column] == 1:
		map = dfs(map, [start_row + 1, start_column])
	if start_column != 0 and map[start_row][start_column - 1] == 1:
		map = dfs(map, [start_row, start_column - 1])
	if start_column != 9 and map[start_row][start_column + 1] == 1:
		map = dfs(map, [start_row, start_column + 1])
	return map


def is_closed(map):
	closed_map = [[0] * 10 for _ in range(10)]
	if map == closed_map:
		return True
	else:
		return False


def make_map(raw_map):
	new_map = [[0] * 10 for _ in range(10)]
	for row in range(10):
		for column in range(10):
			if raw_map[row][column] == 'x':
				new_map[row][column] = 0
			else:
				new_map[row][column] = 1
	return new_map


if __name__ == '__main__':
	is_covered = False
	start = []
	org_map = []

	for row in range(10):
		row_string = input()
		org_map.append(row_string)

		start_column = row_string.find('o')
		if not start and start_column != -1:
			start = [row, start_column]

	# 1 point add map check
	for row in range(10):
		for column in range(10):
			map = make_map(org_map)
			if map[row][column] == 0:
				map[row][column] = 1
				if is_closed(dfs(map, start)):
					print('YES')
					exit()
				map[row][column] = 0
	print('NO')