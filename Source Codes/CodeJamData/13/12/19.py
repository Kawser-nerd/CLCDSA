
import math

def solve(activities,E,R):
	def find_waste_points(a,i,e):
		rec = R
		i+=1
		while a>activities[i]:
			rec += R
			i+=1
		return max(0,min(e,e+rec-E))

	window = int(math.ceil(float(E)/R))+1
	gain = 0
	e = E
	for i,a in enumerate(activities):
		m = max(activities[i:i+window])
		if m==a:
			gain += a*e
			e=0
		else:
			wp = find_waste_points(a,i,e)
			gain += wp*a
			e -= wp
		e+=R
		if e>E:
			e = E
	return gain


tcases = int(raw_input())
for d in xrange(1,tcases+1):
	E,R,N = map(int,raw_input().split())
	activities = map(int,raw_input().split())
	print "Case #%d: %d" % (d,solve(activities,E,R))

