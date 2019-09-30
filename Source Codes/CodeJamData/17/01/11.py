

def solve(pancake_str, k):
	pancakes = list(pancake_str)
	flip_count = 0
	for i in range(len(pancakes)):
		if pancakes[i] == '-':
			flip_count += 1
			for j in range(i,i+k):
				if j >= len(pancakes):
					return 'IMPOSSIBLE'
				pancakes[j] = '+' if pancakes[j] == '-' else '-'
	
	# print 'result:', ''.join(pancakes)
	
	return str(flip_count)
	
case_count = input()
for i in range(1,case_count+1):
	s,k = raw_input().split(' ')
	k = int(k)
	print 'Case #%d: %s' % (i, solve(s,k))