
import sys
fn = sys.argv[1]
f = open(fn,'r')

t = int(f.readline())

def tobase(n,b):
	out = []
	while n > 0:
		out = [n%b]+out
		n /= b
	return out

def happy_iter(n,b):
	x = tobase(n,b)
	total = sum([i*i for i in x])
	return total

def is_happy_3(n):
	while 1:
		n = happy_iter(n,3)
		if n == 1: return True
		if n == 2: return False
		if n == 5: return False
		if n == 8: return False

def is_happy_5(n):
	while 1:
		n = happy_iter(n,5)
		if n == 1: return True
		if n == 4: return False
		if n == 13: return False
		if n == 18: return False

def is_happy_6(n):
	while 1:
		n = happy_iter(n,6)
		if n == 1: return True
		if n == 20: return False

def is_happy_7(n):
	while 1:
		n = happy_iter(n,7)
		if n == 1: return True
		if n == 2: return False
		if n == 25: return False
		if n == 10: return False
		if n == 17: return False
		if n == 45: return False
		if n == 32: return False

def is_happy_8(n):
	while 1:
		n = happy_iter(n,8)
		if n == 1: return True
		if n == 4: return False
		if n == 5: return False
		if n == 26: return False
		if n == 20: return False
		if n == 52: return False

def is_happy_9(n):
	while 1:
		n = happy_iter(n,9)
		if n == 1: return True
		if n == 50: return False
		if n == 53: return False
		if n == 41: return False
		if n == 68: return False
	

def is_happy_10(n):
	while 1:
		n = happy_iter(n,10)
		if n == 1: return True
		if n == 4: return False

def is_happy(n,b):
	if n == 1: return True

	if b == 3: return is_happy_3(n)
	if b == 5: return is_happy_5(n)
	if b == 6: return is_happy_6(n)
	if b == 7: return is_happy_7(n)
	if b == 8: return is_happy_8(n)
	if b == 9: return is_happy_9(n)
	if b == 10: return is_happy_10(n)

def solve(s):
	s = filter(lambda x: x != 2,s)
	s = filter(lambda x: x != 4,s)

	i = 1
	while 1:
		i += 1
		check = True
		for j in s:
			if not is_happy(i,j):
				check = False
				break
		if check:
			return i


for i in range(t):
	bases = [int(x) for x in f.readline().split()]

	print bases
	s = solve(bases)

	print "Case #%d: %d"%(i+1,s)
	sys.stdout.flush()
