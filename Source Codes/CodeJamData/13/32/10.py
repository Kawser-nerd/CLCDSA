T = input()

for case in range(1, T+1):
	[x, y] = map(int, raw_input().strip().split())
	l = "WE" if x > 0 else "EW"
	u = "SN" if y > 0 else "NS" 
	print "Case #%d: %s" % (case, l * abs(x) + u * abs(y))