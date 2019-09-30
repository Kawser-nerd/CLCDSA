def subsets(elements):
	def recurse(elements, start):
		for i in xrange(start, len(elements)):
			d = (elements[i],)
			yield d
			for sub in recurse(elements, i + 1):
				yield d + sub

	for i, e in enumerate(elements):
		d = (e,)
		yield d
		for sub in recurse(elements, i + 1):
			yield d + sub

def disjoint_subsets(elements):
	def recurse(elements, start, disjoint):
		for i in xrange(start, len(elements)):
			d = (elements[i],)
			disj = disjoint + elements[start: i]
			for sub2 in subsets(disj + elements[i+1:]):
				yield d, sub2
			for sub, sub2 in recurse(elements, i + 1, disj):
				yield d + sub, sub2

	for i, e in enumerate(elements):
		d = (e,)
		for sub2 in subsets(elements[i+1:]):
			yield d, sub2
		for sub, sub2 in recurse(elements, i + 1, elements[:0]):
			yield d + sub, sub2

def testCase():
	S = [int(v) for v in raw_input().split()]
	assert len(S) == S[0] + 1
	S.pop(0)
	S.sort()

	for set_a, set_b in disjoint_subsets(S):
		if sum(set_a) == sum(set_b):
			print " ".join(str(v) for v in set_a)
			print " ".join(str(v) for v in set_b)
			return
	print "Impossible"

if __name__ == '__main__':
	n = int(raw_input())
	for i in xrange(n):
		print "Case #%d:" % (i+1,)
		testCase()
