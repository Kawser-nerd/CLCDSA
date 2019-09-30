#!/usr/bin/env python
import math

def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines


def process_lines(lines):
	ans = []
	first = True
	N = -1
	n = 0
	tx = {}
	for line in lines:
		if first == True:
			first = False
		elif N == -1:
			if line != '':
				case = {}
				D = -1
				N = -1
				A = -1
				tx = []
				a = []
				for num in line.split(' '):
					if D == -1:
						D = float(num)
					elif N == -1:
						N = int(num)
					elif A == -1:
						A = int(num)
				case['D'] = D
				case['N'] = N
				case['A'] = A
				n = 1
			else:
				return ans
		elif len(tx) < N:
			split = line.split(' ')
			tx.append((float(split[0]), float(split[1])))
			n += 1
			if n > N:
				case['tx'] = tx
		else:
			for num in line.split(' '):
				a.append(float(num))
			case['a'] = a
			ans.append(case)
			N = -1
	return ans

def process_case(line):
	D = line['D']
	N = line['N']
	A = line['A']
	a = line['a']
	tx = line['tx']
	result = []
	if len(tx) < 2:
		for acc in a:
			a = 0.5 * acc
			b = 0
			c = -D
			t = solveQuadratic(a, b, c)
			result.append(str(t))
		return '\n' + '\n'.join(result)
	if tx[-1][1] > D:
		txNormalize = normalize(tx[-2], tx[-1], D)
		tx[-1] = txNormalize
	#print 'tx'
	#print tx
	for acc in a:
		result.append(solve(D, N, A, acc, tx))
	return '\n' + '\n'.join(result)

def normalize(tx0, tx1, D):
	v = (tx1[1] - tx0[1]) / (tx1[0] - tx0[0])
	newT = tx0[0] + (D - tx0[1]) / v
	return (newT, D)

def solve(D, N, A, acc, tx):
	tpv = (0.0, 0.0, 0.0)
	while tpv[1] < D and len(tx) > 1:
		#print tpv
		tpv = catchUp(D, N, A, acc, tx, tpv)
		tx = tx[1:]
	return str(tpv[0])

def catchUp(D, N, A, acc, tx, tpv):
	t0 = tpv[0]
	v0 = tpv[2]
	p0 = tpv[1]
	txCur = tx[0]
	txNext = tx[1]
	vx = (txNext[1] - txCur[1]) / (txNext[0] - txCur[0])
	px = getPosition(t0, tx, vx)
	'''
	print 'tpv'
	print tpv
	print 'txCur'
	print txCur
	print 'txNext'
	print txNext
	print 'vx'
	print vx
	print 'px'
	print px
	print 'acc'
	print acc
	'''
	a = 0.5 * acc
	b = v0 - vx
	c = p0 - px
	t = solveQuadratic(a, b, c)
	'''
	print 't'
	print t0
	print t
	'''
	if t > txNext[0]:
		#print '>'
		tv = getTimeVel(txNext[1], acc, tpv)
		return (tpv[0] + tv[0], txNext[1], tv[1])
	else:
		#print '<'
		return (txNext[0], txNext[1], vx)

def getTimeVel(p, acc, tpv):
	v = tpv[2]
	'''
	print 'time vel tpv'
	print tpv
	print 'time vel acc'
	print acc
	print 'time vel p'
	print p
	'''
	a = 0.5 * acc
	b = v
	c = tpv[1] - p
	t = solveQuadratic(a, b, c)
	vel = v + t * acc
	'''
	print 'time vel t'
	print t	
	print 'time vel vel'
	print vel
	'''
	return (t, vel)

def solveQuadratic(a, b, c):
	#print 'QUAD'
	#print str(a) + ' ' + str(b) + ' ' + str(c)
	return (-b + math.sqrt(b * b - 4 * a * c)) / (2 * a)

def getPosition(t0, tx, vx):
	return tx[0][1] + (t0 - tx[0][0]) * vx

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))