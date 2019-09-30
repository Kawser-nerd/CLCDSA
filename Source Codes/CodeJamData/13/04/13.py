T = input()

def removed(a, x):
	y = a.index(x)
	return a[:y] + a[y+1:]

def ct(a):
	x = 201*[0]
	for y in a:
		x[y] += 1
	return x


def solve(keys, left, acc):
	#print keys, left, acc
	need = [l[1] for l in left]
	nct = ct(need)
	have = keys[:]
	for l in left:
		have += l[2]
	kct = ct(have)
	for q in range(1,201):
		if kct[q] < nct[q]:
			return []

	for l in left:
		if kct[l[1]] == 1 and l[1] in l[2]:
			return []

	if left == []:
		return acc

	for i in range(len(left)):
		if left[i][1] in keys:
			x =solve(removed(keys,left[i][1])+left[i][2], left[:i]+ left[i+1:], acc + [left[i][0]])
			if x != []:
				return x
	return []

for case in range(T):
	[k,n] = [int(x) for x in raw_input().split()]

	start_keys = [int(x) for x in raw_input().split()]

	chests = []
	for i in range(n):
		line = [int(x) for x in raw_input().split()]
		chests.append([i+1,line[0], line[2:]])

	x= [str(y) for y in solve(start_keys, chests, [])]
	print "Case #%d: %s" %(case + 1,  "IMPOSSIBLE" if x== [] else ' '.join(x))