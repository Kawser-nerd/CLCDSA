# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def Run(v):
	vs = ['+']
	for ch in v[::-1]:
		if ch != vs[-1]:
			vs.append(ch)
	ans = len(vs) - 1
	return ans

lst = ljqpy.LoadList('B-large.in')
outf = 'B-large.out'

with open(outf, 'w') as fout:
	for k, v in enumerate(lst[1:]):
		fout.write('Case #%d: %d\n' % (1+k,Run(v)))

os.system(outf)
print('completed')