
filename = "A-large.in"
lines = [line.rstrip() for line in open(filename, "r")]
no = 1
ll = 1
while ll < len(lines):
	data = map(lambda x: int(x), lines[ll].split())
	ll += 1
	cells = []
	for i in range(data[0]):
		cells.append(lines[ll])
		ll += 1
	
	new_cells = [[None for x in range(data[0])] for x in range(data[0])]
	floors = [1 for x in range(data[0])]
	for x in range(data[0]):
		for y in range(data[0] - 1, -1, -1):
			if cells[x][y] != '.':
				new_cells[data[0] - floors[x]][data[0] - x - 1] = cells[x][y]
				floors[x] += 1

	red = False
	blue = False
	for x in range(data[0]):
		for y in range(data[0]):
			if new_cells[x][y] == None:
				continue
			mode = [
					x <= data[0] - data[1],
					y <= data[0] - data[1],
					False,
					x > data[1] - 2
			]
			mode[2] = mode[0] and mode[1]
			mode[3] = mode[3] and mode[1]
			for i in range(data[1]):
				if mode[0] and new_cells[x+i][y] != new_cells[x][y]:
					mode[0] = False
				if mode[1] and new_cells[x][y+i] != new_cells[x][y]:
					mode[1] = False
				if mode[2] and new_cells[x+i][y+i] != new_cells[x][y]:
					mode[2] = False
				if mode[3] and new_cells[x-i][y+i] != new_cells[x][y]:
					mode[3] = False
				if not (mode[0] or mode[1] or mode[2] or mode[3]):
					break
			if mode[0] or mode[1] or mode[2] or mode[3]:
				if new_cells[x][y] == 'R':
					red = True
				else:
					blue = True
				if red == blue == True:
					break
	if red and blue:
		ret = "Both"
	elif red:
		ret = "Red"
	elif blue:
		ret = "Blue"
	else:
		ret = "Neither"
	print "Case #%d: %s" % (no, ret)
	no += 1

