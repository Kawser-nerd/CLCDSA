import sys, numpy

def main():
	f = open(sys.argv[1])
	T = int(f.readline().strip())
	for i in range(1,T+1):
		(C, F, X) = f.readline().strip().split()

		print "Case #%d: %.7f" % (i, minTime(float(C),float(F),float(X)))

def minTime(C,F,X):
	C = numpy.longdouble(C)
	F = numpy.longdouble(F)
	X = numpy.longdouble(X)
	n = numpy.longdouble(0.0)
	two = numpy.longdouble(2.0)
	prevTime = X/two;
	farmBuildTime = numpy.longdouble(0.0);
	
	while True:
		farmBuildTime += C/(two+n*F)
		n += 1.0
		time = numpy.longdouble(farmBuildTime + X/(two+n*F))
		if time > prevTime:
			return prevTime
		prevTime = time


if __name__ == '__main__':
	main();