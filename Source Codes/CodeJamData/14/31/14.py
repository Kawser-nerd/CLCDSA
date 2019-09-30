#!/bin/sh

import fractions

fname = 'A_example'
fname = 'A_large'

def tokreader(filename):
	for line in open(filename):
		for item in line.strip().split():
			yield item

def readn(n):
    r = []
    for i in xrange(n):
        r.append(read)
    return r

def solve():
	inp = tokreader(fname+'.in')
	read = lambda: inp.next()
	readn = lambda x:[read() for i in xrange(x)]
	outp = open(fname+'.out','w')

	T = int(read())
	for i in range(1,T+1):
		fs = read()

		den = int(fs[:fs.find('/')])
		nom = int(fs[fs.find('/')+1:])

		f = fractions.Fraction(den,nom)
		v = f / fractions.Fraction(1,2**40)

		if (v.denominator != 1):
			res = 'Case #%d: impossible\n'%(i)
		else:
			n1 = v.numerator			
			n2 = 2**39
			r = 1
			while n2 > n1:
				n2 = n2 / 2
				r += 1
			res = 'Case #%d: %d\n'%(i,r)

		print den,nom,v,res

		print res
		outp.write(res)

	outp.close()
	print 'finished'