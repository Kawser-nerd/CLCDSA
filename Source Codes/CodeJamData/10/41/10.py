
filename = "A-large.in"

data = [map(lambda x: int(x), line.rstrip().split()) for line in open(filename, "r")]
ll = 1
qc = 1

while ll < len(data):

	size = data[ll][0]
	cells = data[(ll+1):(ll+2*size)]
	ll += 2 * size

	center = size - 1
	for i in range(len(cells)):

		if i <= center: k = i
		else: k = -i + 2 * center 

		for j in range(len(cells[i]) - 1):
			cells[i].insert(2 * j + 1, " ")
		for j in range(size - k - 1):
			cells[i].insert(0, " ")
			cells[i].append(" ")

	mx = 0
	while True:
		flag = True
		for j in range(1, center - mx + 1):
			for i in range(2 * size - 1):
				if (
						cells[center - mx - j][i] != " " and
						cells[center - mx - j][i] != cells[center - mx + j][i]
				):
					flag = False
					break
			if flag == False:
				break
		if flag:
			break
		if mx != 0:
			flag = True
			for j in range(1, center - mx + 1):
				for i in range(2 * size - 1):
					if (
							cells[center + mx + j][i] != " " and
							cells[center + mx - j][i] != cells[center + mx + j][i]
					):
						flag = False
						break
				if flag == False:
					break
		if flag:
			break
		mx += 1

	my = 0
	while True:
		flag = True
		for j in range(1, center - my + 1):
			for i in range(2 * size - 1):
				if (
						cells[i][center - my - j] != " " and
						cells[i][center - my - j] != cells[i][center - my + j]
				):
					flag = False
					break
			if flag == False:
				break
		if flag:
			break
		if my != 0:
			flag = True
			for j in range(1, center - my + 1):
				for i in range(2 * size - 1):
					if (
							cells[i][center + my + j] != " " and
							cells[i][center + my - j] != cells[i][center + my + j]
					):
						flag = False
						break
				if flag == False:
					break
		if flag:
			break
		my += 1

	ans = (size + mx + my) ** 2  - size * size
	print "Case #%d: %d" % (qc, ans)
	qc += 1
