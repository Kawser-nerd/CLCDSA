from collections import defaultdict
d = defaultdict(int)

rec = [0,0]

N = int(input())
A = list(map(int, input().split()))

for key in A:
	d[key] += 1
	if d[key] == 2:
		if key > rec[0]:
			rec[0] = key
			rec = sorted(rec)
		d[key] = 0

print(rec[0] * rec[1])