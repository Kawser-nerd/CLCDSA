# coding=utf-8

import os, sys, ljqpy, time, random
time.clock()

def CheckNotPrime(x):
	if x % 2 == 0: return 2
	for i in range(3,101,2):
		if i >= x: break
		if x % i == 0: return i
	return 0

def Run(n, j, fout):
	random.seed(1333)
	st = set()
	while j > 0:
		v = [1] + [random.randint(0,1) for x in range(n-2)] + [1]
		zz =  ''.join(str(x) for x in v)
		if zz in st: continue
		st.add(zz)
		rt = []
		for b in range(2, 11):
			z = 0
			for c in v: z = z * b + c 
			rt.append(CheckNotPrime(z))
			if rt[-1] == 0: break
		if rt[-1] != 0:
			print(zz, rt)
			fout.write(zz + ' ')
			fout.write(' '.join(str(x) for x in rt))
			fout.write('\n')
			j -= 1

lst = ljqpy.LoadList('input.txt')
outf = 'C-large.out'

with open(outf, 'w') as fout:
	fout.write('Case #1:\n')
	Run(32, 500, fout)

os.system(outf)
print('completed')