def solve(n,k):
	gap_counts = {
		n: 1
	}
	while True:
		gap = max(gap_counts)
		count = gap_counts[gap]
		hi,lo = gap/2, (gap-1)/2
		if k <= count:
			return '%d %d' % (hi,lo)
		k -= count
		del gap_counts[gap]
		for new_gap in [lo,hi]:
			if new_gap > 0:
				if not new_gap in gap_counts:
					gap_counts[new_gap] = count
				else:
					gap_counts[new_gap] += count
		#print gap_counts

	
case_count = input()
for i in range(1,case_count+1):
	n,k = map(int,raw_input().split(' '))
	print 'Case #%d: %s' % (i, solve(n,k))