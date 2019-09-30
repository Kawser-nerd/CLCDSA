import sys
import time
import re

try:
	import psyco
	psyco.full()
except ImportError:
	pass

class tee: 
	def __init__(self, *fds):
		self._fds = fds
	
	def write(self, data):
		for fd in self._fds:
			fd.write(data)

	def flush(self):
		for fd in self._fds:
			fd.flush()
	
	def close(self):
		for fd in self._fds:
			fd.close()
	

def fileCaseReader(source):
	entryCount = int(source.readline().strip())
	for i in range(1, entryCount + 1):
		yield i

def readLines(source):
	entryCount = int(source.readline().strip())
	for i in range(0, entryCount):
		yield source.readline()

def readLineOfInts(f):
	return map(int, f.readline().strip().split(" "))
		
def calculateGroupIteration(groups, index, seats):
	i = index
	if groups[i] > seats:
		return (0, i)
	total = groups[i]
	i = (i + 1) % len(groups)
	while i != index:
		if groups[i] + total > seats:
			return (total, i)
		total += groups[i]
		i = (i + 1) % len(groups)
	return (total, i)
	
def calculateGroupTable(groups, seats):
	return [calculateGroupIteration(groups, i, seats) for i in range(len(groups))]

def runCase(f):
	R, k, N = readLineOfInts(f)
	groups = readLineOfInts(f)
	groupTable = calculateGroupTable(groups, k)
	g, total = 0, 0
	for i in xrange(R):
		s, g = groupTable[g]
		total += s
		if g == 0:
			#print "*"
			i += 1
			total *= int(R/i)
			R %= i
			for i in xrange(R):
				s, g = groupTable[g]
				total += s
			break
	print total

def timerWrap(f):
	def __inner(*args,**kwargs):
		start = time.time()
		try:
			return f(*args, **kwargs)
		finally:
			print >> sys.stderr, "Runtime: %.3f sec" % (time.time() - start)
	return __inner

#@timerWrap
def main():
	f = file("theme.in", "r");
	sys.stdout = tee(sys.stdout, file("theme.out", "w"))
	for index in fileCaseReader(f):
		print "Case #%d:" % index,
		runCase(f)
		sys.stdout.flush()

main()
