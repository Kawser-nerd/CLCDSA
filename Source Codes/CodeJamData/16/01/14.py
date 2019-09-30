# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def Run(N):
	st = set()
	m = 0
	for i in range(10000000):
		m += N
		for ch in str(m): st.add(ch)
		if len(st) == 10:
			return str(m)
	return 'INSOMNIA'

lst = ljqpy.LoadList('A-large.in')

with open('A-large.out', 'w') as fout:
	for k, v in enumerate(lst[1:]):
		fout.write('Case #%d: %s\n' % (1+k,Run(int(v))))


print('completed')