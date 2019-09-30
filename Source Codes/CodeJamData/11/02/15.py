#!/usr/bin/env python
transform = lambda s: map(lambda x: ord(x) - ord('A'), s)
for testCase in xrange(input()):
	inputStream = raw_input().split()
	combine = [[26] * 26 for _ in xrange(26)]
	for _ in xrange(int(inputStream.pop(0))):
		a, b, c = transform(inputStream.pop(0))
		combine[a][b] = combine[b][a] = c
	opposed = [[] for _ in xrange(26)]
	for _ in xrange(int(inputStream.pop(0))):
		a, b = transform(inputStream.pop(0))
		opposed[a].append(b)
		opposed[b].append(a)
	stack = []
	for newElement in transform(inputStream[1]):
		stack.append(newElement)
		if len(stack) >= 2 and combine[stack[-2]][stack[-1]] != 26:
			combineElement = combine[stack[-2]][stack[-1]]
			stack.pop()
			stack.pop()
			stack.append(combineElement)
			continue
		for opposedElement in opposed[newElement]:
			if opposedElement in stack:
				stack = []
	print filter(lambda x: x != "'", "Case #%d: " %(testCase + 1) + repr(map(lambda x: chr(x + ord('A')), stack)))
