import sys
import math

def isugly(n):
	for p in [2, 3, 5, 7]:
		if n % p == 0:
			return True
	return False

output = []

f = open(sys.argv[1])
try:
	for N in range(1, int(f.next()) + 1):
		digits = list(f.next().strip())
		
		def foo(n):
			if len(n) == 1:
				return 1 if isugly(n[0]) else 0
			
			a = [n[0] + n[1]] + n[2:]
			b = [n[0] - n[1]] + n[2:]
			return foo(a) + foo(b)
		
		def bar(done, todo):
			if len(todo) == 1:
				return [map(int, done + [todo[0]])]
			
			a = bar(done + todo[:1], todo[1:])
			b = bar(list(done), [todo[0] + todo[1]] + todo[2:])
			return a + b
		
		output.append(sum(map(foo, bar([], digits))))
finally:
	f.close()

f = open(sys.argv[2], 'w')
try:
	f.write('\n'.join('Case #%s: %s' % (i + 1, n) for i, n in enumerate(output)))
finally:
	f.close()