n, m = map(int, input().split())

if m<2*n or 4*n<m:
  print('-1 -1 -1')

for b in range(2):
	for a in range(n+1-b):
			if 2 * a + 3 * b + 4 * (n - a - b) == m:
				print(a, b, n-a-b)
				break
	else:
		continue
	break