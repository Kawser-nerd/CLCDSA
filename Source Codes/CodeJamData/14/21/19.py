def compress(s):
	t = []
	prev = '#'
	for c in s:
		if c != prev:
			t.append(c)
		prev = c
	return t

def extract(s):
	res = []
	prev = '#'
	cnt = 1
	for c in s:
		if c != prev and prev != '#':
			res.append(cnt)
			cnt = 1
		else:
			cnt += 1
		prev = c
	res.append(cnt)
	return res

for tc in range(int(input())):
	N = int(input())
	data = []
	for i in range(N):
		data.append(list(input()))

	compressed = compress(data[0])
	valid = True
	for s in data:
		if compressed != compress(s):
			valid = False
			break

	if not valid:
		print('Case #{}: Fegla Won'.format(tc+1))
		continue

	ext = [extract(s) for s in data]
	M = len(ext[0])
	res = 0
	for i in range(M):
		res += min(sum(abs(j - ext[k][i]) for k in range(N)) for j in range(1, 201))
	print('Case #{}: {}'.format(tc+1, res))

