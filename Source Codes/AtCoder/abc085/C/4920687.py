# -*- coding: utf-8 -*-
import sys

n, y = map(int, input().split())

if n * 10000 < y or y % 1000:
	print('-1 -1 -1')
	sys.exit()

for i in range(n + 1):
	for j in range(n - i + 1):
		k = n - i - j
		if k * 10000 + j * 5000 + i * 1000 == y:
			print('{0} {1} {2}'.format(k, j, i))
			sys.exit()

print('-1 -1 -1')