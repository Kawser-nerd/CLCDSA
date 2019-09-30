#!/usr/bin/env python

FILE_NAME_BASE = 'C-large'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	rows, cols = (int(x) for x in inp.readline().split())
	lovers = tuple(int(x) for x in inp.readline().split())
	assert len(lovers) == 2 * (rows + cols)
	pairs = tuple(zip(lovers[::2], lovers[1::2]))
	return rows, cols, pairs

def solve(rows, cols, lovers):
	n = len(lovers) * 2
	lovers = set(tuple(sorted((a - 1, b - 1))) for a, b in lovers)
	done = set()
	maze = [['?'] * cols for _ in xrange(rows)]

	def lover_coord(i):
		if i < cols:
			return -1, i
		if i < cols + rows:
			return i - cols, cols
		if i < cols + rows + cols:
			return rows, cols + rows + cols - 1 - i
		if i < cols + rows + cols + rows:
			return cols + rows + cols + rows - 1 - i, -1
		assert False, i

	while lovers:
		for src, dst in lovers:
			if all(i in done for i in xrange(src + 1, dst)):
				fwd = True
				break
			if all((i % n) in done for i in xrange(dst + 1, n + src)):
				fwd = False
				break
		else:
			return '\nIMPOSSIBLE'

		sr, sc = lover_coord(src)
		dr, dc = lover_coord(dst)
		#print src + 1, '@', (sr, sc), '->', dst + 1, '@', (dr, dc)
		if not fwd:
			sr, sc, dr, dc = dr, dc, sr, sc

		#print '\n'.join(''.join(row) for row in maze)
		#print src + 1, '@', (sr, sc), '->', dst + 1, '@', (dr, dc)
		if sr < 0:
			angle = 2
		elif sc >= cols:
			angle = 3
		elif sr >= rows:
			angle = 0
		elif sc < 0:
			angle = 1
		else:
			assert False

		while True:
			sc += (0, 1, 0, -1)[angle]
			sr += (-1, 0, 1, 0)[angle]
			if not (0 <= sr < rows and 0 <= sc < cols):
				if sr == dr and sc == dc:
					break
				else:
					return '\nIMPOSSIBLE'

			hedge = maze[sr][sc]
			if hedge == '?':
				hedge = ('\\', '/', '\\', '/')[angle]
				maze[sr][sc] = hedge
			if hedge == '/':
				angle = (1, 0, 3, 2)[angle]
			elif hedge == '\\':
				angle = (3, 2, 1, 0)[angle]
			else:
				assert False

		done.add(src)
		done.add(dst)
		lovers.remove((src, dst))

	for row in xrange(rows):
		for col in xrange(cols):
			if maze[row][col] == '?':
				maze[row][col] = '/'

	return '\n' + '\n'.join(''.join(row) for row in maze)

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	with open(FILE_NAME_BASE + '.in', 'r') as inp:
		numCases = int(inp.readline())
		inputs = [parse(inp) for _ in xrange(numCases)]

	if NUM_PROCESSES == 0:
		runners = [lambda inp=inp: apply(solve, inp) for inp in inputs]
	else:
		from multiprocessing import Pool
		from signal import SIGINT, SIG_IGN, signal
		pool = Pool(NUM_PROCESSES, signal, (SIGINT, SIG_IGN))
		runners = [pool.apply_async(solve, inp).get for inp in inputs]
		pool.close()

	caseFmt = '%' + str(len(str(numCases))) + 'd'
	progressFmt = '[%s/%s] %%s\n' % (caseFmt, caseFmt)
	with open(FILE_NAME_BASE + '.out', 'w') as out:
		for case, runner in enumerate(runners, 1):
			result = runner()
			out.write('Case #%d: %s\n' % (case, result))
			out.flush()
			sys.stderr.write(progressFmt % (case, numCases, result))

if __name__ == '__main__':
	main()
