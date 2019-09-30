import sys
inp = sys.stdin.readlines()

cases = int(inp.pop(0))

for case in range(1, cases + 1):
	word = inp.pop(0).strip()
	result = word[0]
	word = word[1:]
	while word:
		letter = word[0]
		word = word[1:]
		if letter >= result[0]:
			result = letter + result
		else:
			result = result + letter
	print 'Case #{}: {}'.format(case, result)
