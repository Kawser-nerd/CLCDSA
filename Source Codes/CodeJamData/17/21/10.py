def solve(d,n,horses):
	def comp(a,b):
		return d*b[1]-a[0]*b[1] -( d*a[1] - a[1]*b[0])
	ranked = sorted(horses,cmp=comp)
	#print ranked
	slowest = ranked[-1]
	return float(d*slowest[1])/(d-slowest[0])

T = int(input())
for case in range(1,T+1):
	d,n = tuple(map(int,raw_input().split()))
	horses = [ tuple(map(int,raw_input().split())) for i in range(n)]
	print("Case #{}: {}".format(case, solve(d,n,horses)))
