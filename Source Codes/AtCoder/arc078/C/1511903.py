import sys
N = 0
debug = False
def test_init():
	N = int(input())
def test_eval(n):
	return ((n <= N and str(n) <= str(N)) or (n > N and str(n) > str(N)))

def query(n):
	# print(n, N, test_eval(n))
	if debug:
		return test_eval(n)
	print("? " + str(n))
	sys.stdout.flush()
	return input() == "Y"

def get_ndigit():
	retval = 1
	while not query(10 ** retval - 1):
		retval += 1
	if retval == 1:
		while not query((10 ** retval - 1) * 10 ** 9):
			retval += 1
		while not query(10 ** retval - 1):
			retval += 1
	return retval

def get_digit(x):
	l = len(str(x)) if x != 0 else 0
	def q(D):
		return query(x * 10 + D)
	d = 5
	r = q(d)
	if r:
		d = 7
		r = q(d)
		if r:
			d = 8
			r = q(d)
			if r:
				d = 9
				r = q(d)
				return 9 if r else 8
			else:
				return 7
		else:
			d = 6
			r = q(d)
			return 6 if r else 5
	else:
		d = 2
		r = q(d)
		if r:
			d = 3
			r = q(d)
			if r:
				d = 4
				r = q(d)
				return 4 if r else 3
			else:
				return 2
		else:
			d = 1
			r = q(d)
			return 1 if r else 0
if debug:
	test_init()
nd = get_ndigit()
# print(nd)
value = 0
for i in range(nd - 1):
	value = value * 10 + get_digit(value)
ar = [False] * 10
i = 0
if nd == 1:
	i = 1
while not query((value * 10 + i) * 10):
	i += 1
value = value * 10 + i
print("! " + str(value))