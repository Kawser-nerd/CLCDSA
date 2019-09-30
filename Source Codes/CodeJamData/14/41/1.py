#!/usr/bin/python
#
# GCJ 2014, Round 2
# Task 'X' by Veselin Georgiev
#

def solve():
	n, cap = map(int, raw_input().strip().split())
	items = sorted(map(int, raw_input().strip().split()))
	i = 0
	j = n - 1
	count = 0
	while i < j:
		count += 1
		if items[j] + items[i] > cap:
			j -= 1
		else:
			j -= 1
			i += 1

	if i == j:
		count += 1

	return count

def main():
	nTests = int(raw_input().strip())
	for i in xrange(nTests):
		print "Case #%d:" % (i + 1), solve()
		

if __name__ == "__main__":
	main()
	