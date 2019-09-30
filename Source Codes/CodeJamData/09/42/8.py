
import os, sys, re, string

def readint():
	return int(sys.stdin.readline())
def readints(sp=" "):
	return map(lambda x: int(x), sys.stdin.readline().split(sp))


def compile(s):
	return map(lambda ch: 0 if ch == '.' else 1, s)

def operate():
	rows, cols, fall = readints()
	data = map(lambda x: compile(sys.stdin.readline().strip()), range(rows))
	def diggable_left(data, x, y):
		return x > 0 and data[y][x - 1] == 0 and data[y+1][x-1] == 1
	def diggable_right(data, x, y):
		return x < cols - 1 and data[y][x+1] == 0 and data[y+1][x+1] == 1
	def movable_left(data, x, y):
		return x > 0 and data[y][x-1] == 0
	def movable_right(data, x, y):
		return x < cols - 1 and data[y][x+1] == 0
	def is_falling(data, x, y):
		return data[y+1][x] == 0
	def printout(data, x, y):
		print '--------------------------'
		for i in xrange(rows):
			s = ''
			for j in xrange(cols):
				if i == y and x == j:
					s += '*'
				elif data[i][j] == 0:
					s += ' '
				else:
					s += '#'
			print s
	def vec2tuple(data):
		return tuple(map(lambda x: tuple(x), data))
	cache = {}
	def f(data, x, y, dig, tdata):
		if is_falling(data, x, y):
			count = 0
			while y+1 < rows and is_falling(data, x, y):
				count += 1
				y += 1
			if count > fall:
				return 9999999
		key = (x, y)
		#print x, y, dig
		#printout(data, x, y)
		if cache[tdata].has_key(key):
			if cache[tdata][key] <= dig:
				return cache[tdata][key]
		cache[tdata][key] = dig
		if y == rows - 1:
			#print x,y,dig
			#printout(data, x, y)
			return dig
		res = 999999
		if diggable_left(data, x, y):
			data[y+1][x-1] = 0
			tdata2 = vec2tuple(data)
			if not cache.has_key(tdata2):
				cache[tdata2] = {}
			res = min(res, f(data, x, y, dig + 1, tdata2))
			data[y+1][x-1] = 1
		if diggable_right(data, x, y):
			data[y+1][x+1] = 0
			tdata2 = vec2tuple(data)
			if not cache.has_key(tdata2):
				cache[tdata2] = {}
			res = min(f(data, x, y, dig + 1, tdata2), res)
			data[y+1][x+1] = 1
		if movable_left(data, x, y):
			res = min(f(data, x - 1, y, dig, tdata), res)
		if movable_right(data, x, y):
			res = min(f(data, x + 1, y, dig, tdata), res)
	tdata = vec2tuple(data)
	cache[tdata] = {}
	f(data, 0, 0, 0, tdata)
	res = 9999999999
	for value in cache.values():
		for t in value:
			if t[1] == rows - 1:
				res = min(res, value[t])
	return "No" if res > 99999999 else "Yes %d" % res

def main():
	print "\n".join(map(lambda x: "Case #%d: %s" % (x, operate()), range(1, readint()+1)))

if __name__ == '__main__':
	main()

