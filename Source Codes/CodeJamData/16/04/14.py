# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def RunSmall(v):
	k, c, s = map(int, v.split())
	ans = [(i+1)*k**(c-1) for i in range(k)]
	return ' '.join(str(x) for x in ans)

def Run(v):
	k, c, s = map(int, v.split())
	if s * c < k: return 'IMPOSSIBLE'
	ans = []
	for ii in range(1, k+1, c):
		z = 1
		for jj in range(ii, min([ii+c, k+1])):
			z += (jj-1) * (k ** (c-(jj-ii)-1))
		ans.append(z)
	return ' '.join(str(x) for x in ans)

lst = ljqpy.LoadList('D-large.in')
outf = 'D-large.out'

with open(outf, 'w') as fout:
	for k, v in enumerate(lst[1:]):
		fout.write('Case #%d: %s\n' % (1+k,Run(v)))

os.system(outf)
print('completed')