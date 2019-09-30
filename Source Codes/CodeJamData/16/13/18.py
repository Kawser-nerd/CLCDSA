#!/usr/bin/env pypy
import itertools

def get_cycles_and_hairpins(a):
	h = [] # [..., u, v, u]
	c = [] # 3+-cycles
	has_pred = set(a)
	for i in xrange(len(a)):
		q = [i]
		s = set(q)
		for j in q:
			assert j == q[-1]
			j = a[j]
			if j not in s:
				pass
			elif j == q[-2]:
				#if i not in has_pred:
				if True:
					#print 'hairpin:', q + [j]
					h.append(q)
				break
			else:
				if j == q[0]:
					if i == min(q):
						#print 'cycle:', q + [j]
						c.append(q)
				break
			q.append(j)
			s.add(j)
	return c, h

def solve(a):
	#return brute_force(a)
	c, h = get_cycles_and_hairpins(a)
	c = map(len, c)
	hairpins = {}
	for hairpin in h:
		tail = tuple(hairpin[-2:])
		hairpins[tail] = max(hairpins.get(tail, []), hairpin, key=len)
	maxlen = {}
	for tail, hairpin in hairpins.iteritems():
		tail2 = tuple(sorted(tail))
		l = len(hairpin)
		if tail2 not in maxlen:
			maxlen[tail2] = l
		else:
			maxlen[tail2] = maxlen[tail2] - 2 + l
	return max(c + [sum(maxlen.values())])

def brute_force(a):
	n = len(a)
	ret = 0
	for contained in itertools.product([False, True], repeat=n):
		for p in itertools.permutations(itertools.compress(xrange(n), contained)):
			l = len(p)
			for i in xrange(l):
				if a[p[i]] not in (p[i-1], p[i-l+1]):
					break
			else:
				ret = max(ret, l)
	return ret

def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		N = int(raw_input())
		a = [int(w) - 1 for w in raw_input().split()]
		print solve(a)

if __name__ == '__main__':
	main()
