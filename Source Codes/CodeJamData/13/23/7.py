import sys

words = set()
for word in open('garbled_email_dictionary.txt'):
###for word in open('tdict.txt'):
	word = word.strip()
	words.add(word)
	for i in xrange(len(word)):
		nword = word[:i] + '.' + word[i+1:]
		words.add(nword)
	if len(word) > 5:
		for i in xrange(len(word) - 5):
			for j in xrange(i+5, len(word)):
				nword = word[:i] + '.' + word[i+1:j] + '.' + word[j+1:]
				words.add(nword)

cases = int(sys.stdin.readline())
for case in xrange(1, cases + 1):
	changes = 1e6
	word = sys.stdin.readline().strip()
	scores = [[1e7 for i in xrange(5)] for j in xrange(len(word) + 1)]
	scores[0][-5] = 0
	for pos in xrange(len(word)):
		for i in xrange(-1, -6, -1):
			if scores[pos][i] < 0:
				continue
			for wlen in xrange(1, 10):
				if pos + wlen > len(word):
					continue
				nword = word[pos:pos + wlen]
				# Check no changes
				if nword in words:
					prev = i - wlen
					if prev < -5:
						prev = -5
					if scores[pos + wlen][prev] > scores[pos][i]:
						scores[pos + wlen][prev] = scores[pos][i]

				# Chaeck one change
				for j in xrange(len(nword)):
					if j - i >= 5:
						tword = nword[:j] + '.' + nword[j+1:]
						if tword in words:
							prev = j - len(nword)
							if prev < -5:
								prev = -5
							if scores[pos + wlen][prev] > scores[pos][i] + 1:
								scores[pos + wlen][prev] = scores[pos][i] + 1

				# Check two changes
				for j in xrange(len(nword)):
					if j - i >= 5:
						for k in xrange(j + 5, len(nword)):
							tword = nword[:j] + '.' + nword[j+1:k] + '.' + nword[k+1:]
							if tword in words:
								prev = k - len(nword)
								if prev < -5:
									prev = -5
								if scores[pos + wlen][prev] > scores[pos][i] + 2:
									scores[pos + wlen][prev] = scores[pos][i] + 2
###	for line in scores:
###		print line
	for val in scores[-1]:
		if val >= 0:
			changes = min(changes, val)
	print "Case #%d: %d" % (case, changes)
