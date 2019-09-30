# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def GetNum(v):
	nn = 0
	while v > 0:
		v -= v & (-v)
		nn += 1
	return nn

def Dfs(mat, ii, et, sts):
	if ii >= N: return True
	for i in range(N):
		if (1<<i) & et: continue
		nsts = set()
		for st in sts:
			ok = False
			for v in range(N):
				if not mat[i][v] or ((1<<v) & st): continue
				ok = True
				nsts.add(st|(1<<v))
			if not ok: return False
		if not Dfs(mat, ii+1, et|(1<<i), nsts): return False
	return True

def Check(mt):
	mat = [ [((1<<(x*N+y)) & mt > 0) for y in range(N)] for x in range(N)]
	if not Dfs(mat, 0, 0, [0]): return False
	return True

	
def Run():
	global N, lst
	N = int(lst[0])
	mat = lst[1:N+1]
	lst = lst[N+1:]
	mns = N * N
	mvv = sum( [ sum([int(mat[x][y])<<(x*N+y) for y in range(N)]) for x in range(N)] )
	ret = mns
	for v in range(2**mns):
		if v & mvv: continue
		nn = GetNum(v)
		if nn >= ret: continue
		if Check(mvv+v): ret = nn
	return '%d' % ret

lst = ljqpy.LoadList('D-small-attempt0.in')
outf = 'D-small-attempt0.out'

with open(outf, 'w') as fout:
	N = int(lst[0])
	lst = lst[1:]
	for k in range(N):
		fout.write('Case #%d: %s\n' % (1+k,Run()))
		fout.flush()

os.system('emeditor.exe ' + outf)
print('completed')