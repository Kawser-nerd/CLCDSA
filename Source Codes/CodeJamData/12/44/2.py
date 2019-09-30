from sys import stdout
from copy import deepcopy

def reachable(mat, x, y, s):
	if mat[y][x] == '#':
		return 0
	if (x, y) in s:
		return 0
	s.add((x, y))
	reachable(mat, x - 1, y, s)
	reachable(mat, x + 1, y, s)
	reachable(mat, x, y - 1, s)
	return s

# assumes manhattan movement
def new_pos(mat, x, y, new_x, new_y, cave):
	if mat[new_y][new_x] == '#':# or mat[y][x] == cave:
		return (x, y)
	return (new_x, new_y)

# matrix, desired-set, reachable-set, current-set
def plan(mat, d, r, c, m, cave):
	#print c, d
	#return True
	if c == d:
		return True
	if tuple(c) in m:
		#print tuple(c)
		return False
	m.add(tuple(c))
	# try left
	new = set(new_pos(mat, x, y, x - 1, y, cave) for x, y in c)
	if new.issubset(r) and new != c:
		if plan(mat, d, r, new, m, cave):
			#print 'left'
			return True
	# try right
	new = set(new_pos(mat, x, y, x + 1, y, cave) for x, y in c)
	if new.issubset(r) and new != c:
		if plan(mat, d, r, new, m, cave):
			#print 'right'
			return True
	# try down
	new = set(new_pos(mat, x, y, x, y + 1, cave) for x, y in c)
	if new.issubset(r) and new != c:
		if plan(mat, d, r, new, m, cave):
			#print 'down'
			return True
	#print tuple(c)
	return False

def solve(mat):
	pos = {}
	for y in xrange(len(mat)):
		for x in xrange(len(mat[y])):
			if mat[y][x] not in '.#':
				pos[mat[y][x]] = (x, y)
	for cave in sorted(pos):
		r = reachable(mat, pos[cave][0], pos[cave][1], set())
		nr = len(r) # num-reachable
		lucky = plan(mat, set([(pos[cave][0], pos[cave][1])]), r, deepcopy(r), set(), cave)
		if lucky:
			lucky = "Lucky"
		else:
			lucky = "Unlucky"
		stdout.write("%s: %s %s\n" % (cave, nr, lucky))

t = int(raw_input())
for case in xrange(1, t + 1):
	r, c = [int(d) for d in raw_input().split()]
	m = [raw_input() for j in xrange(r)]
	stdout.write("Case #%d:\n" % case)
	solve(m)
