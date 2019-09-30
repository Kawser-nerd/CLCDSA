import itertools
N = int(input())
k = ['a', 'b', 'c']
for ans in itertools.product(k, repeat = N):
	print(*ans, sep='')