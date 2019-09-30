

f_in = open("../Downloads/A-large.in")
N = int(f_in.readline().rstrip())
for test_case in range(N):
	n = int(f_in.readline().rstrip())
	x = (f_in.readline().rstrip().split(" "))
	y = (f_in.readline().rstrip().split(" "))
	if (not (len(x) == len(y)) or (not (n == len(x)))):
		print "****** NOT EQUAL LENS****"
	for ii in range(n):
		x[ii] = int(x[ii])
		y[ii] = int(y[ii])
	x.sort()
	y.sort()
	y.reverse()
	min_sum = 0L
	for ii in range(n):
		min_sum = min_sum + x[ii]*y[ii]
	print "Case #%d: %d" %(test_case + 1, min_sum)
				
					
	
