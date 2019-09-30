#!/usr/bin/env python
from math import floor, ceil, sqrt

precision = 0.01

def seeReflection(x, v, m, d):
	cur_y = x[0]
	cur_x = x[1]
	vy = v[0]
	vx = v[1]
	dist = 0
	while dist <= d + precision:
		if abs(cur_x - x[1]) < precision and abs(cur_y - x[0]) < precision and dist > 0:
			#print str(dist) + ' ' + str(v)
			return True

		if vy == 0:
			if vx < 0:
				cur_x -= 0.5
			else:
				cur_x += 0.5
			if abs(cur_x - round(cur_x)) < precision:
				if vx < 0 and m[int(floor(cur_y))][int(round(cur_x) - 1)] == 1:
					vx = -vx
				elif vx > 0 and m[int(floor(cur_y))][int(round(cur_x))] == 1:
					vx = -vx
			dist += 0.5
		elif vx == 0:
			if vy < 0:
				cur_y -= 0.5
			else:
				cur_y += 0.5
			if abs(cur_y - round(cur_y)) < precision:
				if vy < 0 and m[int(round(cur_y) - 1)][int(floor(cur_x))] == 1:
					vy = -vy
				elif vy > 0 and m[int(round(cur_y))][int(floor(cur_x))] == 1:
					vy = -vy
			dist += 0.5
		else:
			# Find how far is the next time we hit something .0 or .5
			if vy < 0:
				dy = cur_y - floor(cur_y)
			else:
				dy = ceil(cur_y) - cur_y
			if dy > 0.5 + precision:
				dy -= 0.5
			elif dy < precision:
				dy += 0.5

			if vx < 0:
				dx = cur_x - floor(cur_x)
			else:
				dx = ceil(cur_x) - cur_x
			if dx > 0.5 + precision:
				dx -= 0.5
			elif dx < precision:
				dx += 0.5

			# See which will come up first
			ty = dy / abs(vy)
			tx = dx / abs(vx)
			if ty > tx:
				t = tx
			else:
				t = ty

			dy = vy * t
			dx = vx * t
			cur_y = cur_y + dy
			cur_x = cur_x + dx
			dist += sqrt(dy * dy + dx * dx)
			#print "%f [%f, %f] (%d, %d)" % (dist, cur_y, cur_x, vy, vx)

			roundy = round(cur_y)
			roundx = round(cur_x)
			ybounce = False
			xbounce = False
			if abs(cur_y - roundy) < precision and abs(cur_x - roundx) < precision:
				# Case we're at a corner
				neighbors = []
				intx = int(roundx)
				inty = int(roundy)
				neighbors.append(m[inty - 1][intx - 1] % 2)
				neighbors.append(m[inty - 1][intx] % 2)
				neighbors.append(m[inty][intx] % 2)
				neighbors.append(m[inty][intx - 1] % 2)
				sum = 0
				for neighbor in neighbors:
					sum += neighbor
				if sum == 1:
					if vy < 0:
						nexty = inty - 1
					else:
						nexty = inty
					if vx < 0:
						nextx = intx - 1
					else:
						nextx = intx
					if m[nexty][nextx] == 1:
						return False
				elif sum == 3:
					vy = -vy
					vx = -vx
				elif sum == 2:
					if neighbors[0] == neighbors[1]:
						vy = -vy
					elif neighbors[0] == neighbors[3]:
						vx = -vx
			elif abs(cur_y - roundy) < precision:
				# Case we're middle of a top/bottom edge
				if vy < 0:
					inty = int(roundy - 1)
				else:
					inty = int(roundy)
				intx = int(floor(cur_x))
				if m[inty][intx] == 1:
					vy = -vy
			elif abs(cur_x - roundx) < precision:
				# Case we're middle of a top/bottom edge
				if vx < 0:
					intx = int(roundx - 1)
				else:
					intx = int(roundx)
				inty = int(floor(cur_y))
				if m[inty][intx] == 1:
					vx = -vx
	return False


def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines

def process_lines(lines):
	ans = []
	first = True
	inProgress = False
	for line in lines:
		if first == True:
			first = False
		else:
			if inProgress:
				if len(m) == H - 1:
					inProgress = False
				row = []
				for char in line:
					if char == '#':
						row.append(1)
					elif char == '.':
						row.append(0)
					elif char == 'X':
						row.append(2)
				m.append(row)
				if not inProgress:
					case['m'] = m
					ans.append(case)
			elif line != '':
				inProgress = True
				case = {}
				H = -1
				W = -1
				D = -1
				m = []
				for num in line.split(' '):
					if H == -1:
						H = int(num)
					elif W == -1:
						W = int(num)
					elif D == -1:
						D = int(num)
				case['H'] = H
				case['W'] = W
				case['D'] = D
	return ans

def process_case(line):
	H = line['H']
	W = line['W']
	D = line['D']
	m = line['m']

	vectors = set()
	ratios = set()
	for i in range(D + 1):
		for j in range(1, D + 1):
			if i <= j and i*i + j*j <= D * D:
				ratio = float(i) / float(j)
				if ratio not in ratios:
					vectors.add((i, j))
					vectors.add((i, -j))
					vectors.add((-i, j))
					vectors.add((-i, -j))
					vectors.add((j, i))
					vectors.add((j, -i))
					vectors.add((-j, i))
					vectors.add((-j, -i))
					ratios.add(ratio)
	x = None
	for i in range(H):
		for j in range(W):
			if x == None and m[i][j] == 2:
				x = (i + 0.5, j + 0.5)
	count = 0
	for vector in vectors:
		if seeReflection(x, vector, m, D):
			count += 1
	return count

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))