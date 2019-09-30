from collections import Counter

n = int(input())
a = list(map(int, input().split()))
c = Counter(a)
ok = True

d_max = max(a)
if n > 2 and d_max == 1:
	ok = False
if c[d_max] == 1:
	ok = False
else:
	if d_max % 2 == 0:
		d_min = d_max // 2
		if min(a) < d_min:
			ok = False
		if c[d_min] != 1:
			ok = False
		for d in range(d_min + 1, d_max):
			if c[d] < 2:
				ok = False

	else:
		d_min = (d_max + 1) // 2
		if min(a) < d_min:
			ok = False
		if c[d_min] != 2:
			ok = False
		for d in range(d_min + 1, d_max):
			if c[d] < 2:
				ok = False

if ok:
	print("Possible")
else:
	print("Impossible")