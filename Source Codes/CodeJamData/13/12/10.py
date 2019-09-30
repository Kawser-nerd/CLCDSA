def solve(start, end, regain, maximum, weights):
	if not weights:
		return 0
	high = max(range(len(weights)),key=lambda x:weights[x])
	x = start + regain * high
	y = end - regain * (len(weights)-high)
	if x > maximum:
		x = maximum
	
	if y < 0:
		y = 0
	left  = solve(start, x, regain, maximum, weights[:high])
	right = solve(y + regain, end,   regain, maximum, weights[high+1:])
	return left + right + (x-y)*weights[high]

n_cases = input()

for case in range(1,n_cases+1):
	maximum, regain, n = map(int, raw_input().split())
	weights = map(int, raw_input().split())
	print 'Case #%d: %d' % (case, solve(maximum, 0, regain, maximum, weights))