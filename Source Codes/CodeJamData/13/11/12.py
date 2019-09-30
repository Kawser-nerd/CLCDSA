from math import pi

def calc(r, n): # 2r+1 + 2r+5 + ... + 2r+4n-3
	tot = 2*n*n-n
	tot += 2*r*n
	return tot

tc = input()
for l in range(1, tc+1):
	r, t = map(int, raw_input().split(' '))
	mn = 0
	mx = 10**40
	while mn < mx:
		mid = (mn+mx+1)/2
		if calc(r, mid) > t:
			mx = mid-1
		else:
			mn = mid
	print "Case #"+repr(l)+": "+repr(int(mn))
