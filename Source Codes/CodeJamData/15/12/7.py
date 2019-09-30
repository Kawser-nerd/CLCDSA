

global times 
global B,N 

def check_time(ctime):
	total = 0
	next = 0
	current = 0
	for t in times:
		total += long(ctime/t)
		if (ctime % t) == 0:
			next += 1
		else:
			current += 1

	if(total+current >= N):
		return -1

	if(total+current+next < N):
		return 1

	else:
		return 0
	

def get_num(ctime):
	total = 0
	for t in times:
		total += long(ctime/t)
		if (ctime % t > 0):
			total += 1

	left = N - total
	for (idx,t) in enumerate(times):
		if (ctime % t) == 0:
			left -= 1
			if left == 0:
				return idx + 1

	return -1

def main():
	global times,B,N
	inf = open('./B-large.in','r')
	test_cases = int(inf.readline())

	for test_case in range(1,test_cases+1):
		first = inf.readline()
		B,N = [long(x) for x in first.split(' ')]
		times = [ long(x) for x in inf.readline().split(' ') ]

		low = 0
		high = max(times) * N + 1
		correct = -1
		while low < high:
			mid = (low) + (high-low) / 2
			ret = check_time(mid)
			if ret == -1:
				high = mid
			elif ret == 1:
				low = mid + 1
			else:
				correct = mid
				break

		print "Case #%d: %d" % (test_case, get_num(correct))


main()