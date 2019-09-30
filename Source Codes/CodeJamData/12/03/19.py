import math

T=int(raw_input())
for repeat in xrange(T):
	line_arr=raw_input().split()
	A,B=int(line_arr[0]),int(line_arr[1])
	n=int(math.log10(B))+1
	count=0
	for w in xrange(1,n):
		wr=pow(10,w)
		wl=pow(10,n-w)
		for x in xrange(A,B+1):
			y=x/wr+x%wr*wl
			if y>x and y<=B:
				if wr<=wl: count+=1
				elif y!=x/wl+x%wl*wr: count+=1
	print "Case #%d: %d"%(repeat+1,count)
