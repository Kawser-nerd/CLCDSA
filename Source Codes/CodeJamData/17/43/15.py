import numpy as np


inname = "input.txt"
outname = "output.txt"

with open(inname, 'r') as f:
	cases = int(f.readline())
	for tc in range(1,cases+1):
		line = f.readline().strip().split(' ')
		R = int(line[0])
		C = int(line[1])
		grid = []
		cells = []
		lasers = []
		for i in range(R):
			grid.append([0]*C)
			cells.append([0]*C)
			line = f.readline().strip()
			for j in range(C):
				if line[j] == '.':
					grid[i][j] = 0
					cells[i][j] = []
				elif line[j] == '#':
					grid[i][j] = 1
				elif line[j] == '|' or line[j] == '-':
					grid[i][j] = 2
					lasers.append([(i, j), 0]) #1 = -; 2 = |

		L = len(lasers)
		possible = True
		rules = []
		for i in range(L):
			r, c = lasers[i][0]
			rr = r-1
			while rr >= 0:
				if grid[rr][c] == 0:
					cells[rr][c].append((i, 2))
				elif grid[rr][c] == 1:
					break
				else:
					rules.append((i, 1))
				rr -= 1
			rr = r+1
			while rr < R:
				if grid[rr][c] == 0:
					cells[rr][c].append((i, 2))
				elif grid[rr][c] == 1:
					break
				else:
					rules.append((i, 1))
				rr += 1
			cc = c-1
			while cc >= 0:
				if grid[r][cc] == 0:
					cells[r][cc].append((i, 1))
				elif grid[r][cc] == 1:
					break
				else:
					rules.append((i, 2))
				cc -= 1
			cc = c+1
			while cc < C:
				if grid[r][cc] == 0:
					cells[r][cc].append((i, 1))
				elif grid[r][cc] == 1:
					break
				else:
					rules.append((i, 2))
				cc += 1

		finallaser = [0]*L
		for i in range(len(rules)):
			l, d = rules[i]
			if finallaser[l] == 0:
				finallaser[l] = d
			else:
				possible = False
				break
		for r in range(R):
			for c in range(C):
				if cells[r][c] != 0:
					if len(cells[r][c]) == 0:
						possible = False
						break
					elif len(cells[r][c]) == 1:
						l, d = cells[r][c][0]
						if finallaser[l] > 0 and finallaser[l] != d:
							possible = False
							break
						else:
							finallaser[l] = d
		for r in range(R):
			for c in range(C):
				if cells[r][c] != 0 and len(cells[r][c]) == 2:
					l1, d1 = cells[r][c][0]
					l2, d2 = cells[r][c][1]
					if finallaser[l1] == 0:
						finallaser[l1] = d1
					elif finallaser[l1] == d1:
						pass
					else:
						if finallaser[l2] == 0:
							finallaser[l2] = d2
						elif finallaser[l2] == d2:
							pass
						else:
							possible = False
							break

		if not possible:
			print("Case #%d: IMPOSSIBLE" % tc)
		else:
			#print(finallaser)
			finalgrid = []
			for i in range(R):
				finalgrid.append(['.']*C)
				for j in range(C):
					if grid[i][j] == 0:
						finalgrid[i][j] = '.'
					elif grid[i][j] == 1:
						finalgrid[i][j] = '#'
			for i in range(L):
				d = finallaser[i]
				if d == 0:
					d = 1
				r,c = lasers[i][0]
				if d == 1:
					finalgrid[r][c] = '-'
				else:
					finalgrid[r][c] = '|'

			print("Case #%d: POSSIBLE" % tc)
			for i in range(R):
				print("".join(finalgrid[i]))
