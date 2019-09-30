import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
	return int(read_word(f), b)

def read_letters(f):
	return list(read_word(f))

def read_digits(f, b=10):
	return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
	return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
	return [int(x, b) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
	res = []
	for i in range(R):
		res.append(reader(f, *args, **kwargs))
	return res

def solve(solver, fn, out_fn=None):
	in_fn = fn + '.in'
	if out_fn is None:
		out_fn = fn + '.out'
	with open(in_fn, 'r') as fi:
		with open(out_fn, 'w') as fo:
			T = read_int(fi)
			for i in range(T):
				case = read_case(fi)
				res = solver(case)
				write_case(fo, i, res)

################################################################################

def read_case(f):
	w, n = read_words(f)
	n = int(n)
	return (w, n)

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')

################################################################################

vowels = ['a', 'e', 'i', 'o', 'u']

def substring(w, n):
	count = 0
	start = -1
	for i in range(len(w)):
		if w[i] in vowels:
			if count >= n:
				return (start, i-1)
			start = -1
			count = 0
			continue
		else:
			if start == -1: start = i
			count = count + 1
	if start != -1 and len(w) - start >= n: return (start, len(w)-1)
	return (-1, 0)

def find_first(w, n):
	if w == None: return 0
	(s, e) = substring(w, n)
	if s == -1: return 0
	length = e-s+1
	tail = len(w) - e -1
	if length == n:
		return (s+1)*(tail+1) + find_first('a'*(n-1)+w[e+1:],n)
	else:
		ext = length - n + 1
		withhead = s*ext
		withtail = tail*ext
		print "s, e:", s, e
		print "h, t:", withhead, withtail
		return (s)*(tail)+withhead + withtail + (ext+1)*ext/2 + find_first('a'*(n-1)+w[e+1:],n)

def solve_small(case):
	w, n = case
	return find_first(w, n)

solve_large = solve_small

solve(solve_large, 'A-large')
