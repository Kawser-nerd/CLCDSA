#!/usr/bin/python3

import sys

def makemap():
	ALPHA = 'abcdefghijklmnopqrstuvwxyz'
	M = { 'y':'a',
			'e':'o',
			'q':'z', }
	G = '''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv'''
	E = '''our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up'''
	assert(len(G) == len(E))
	for i in range(len(G)):
		g = G[i]
		e = E[i]
		if g in ALPHA:
			assert (e in ALPHA)
			if g not in M:
				M[g] = e
			else:
				assert(M[g] == e)
		else:
			assert (e not in ALPHA)

	assert (len(M) == 25 or len(M) == 26)
	assert (len(M) == len(set(M.values())))
	if len(M) == 25:
		g = ''.join(c for c in ALPHA if c not in M)
		e = ''.join(c for c in ALPHA if c not in M.values())
		M[g] = e
	assert (len(M) == len(set(M.values())))
	assert (set(M) == set(ALPHA))
	return M


def trans(s,M):
	return ''.join(M.get(c,c) for c in s)

def main():
	M = makemap()
	T = int(sys.stdin.readline().strip())
	for i in range(T):
		s = sys.stdin.readline()
		s = trans(s, M)
		sys.stdout.write('Case #{}: '.format(i+1))
		sys.stdout.write(s)

if __name__ == '__main__':
	main()
