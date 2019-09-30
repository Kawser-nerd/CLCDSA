from math import *
import string

MOD = 1000000000+7

def process(word):
	enc = []
	for l in word:
		if len(enc) == 0:
			enc.append(l)
		elif enc[-1] == l:
			continue
		elif l not in enc:
			enc.append(l)
		else:
			return -1
	return enc

def test(let, ptr):
	count = 0
	curr = let
	while count < 40:
		if curr not in ptr:
			return 1
		curr = ptr[curr]
		count+=1
	return 0

def valid(ptr):
	chck = {}
	count = 0
	for let in string.lowercase:
		curr = let
		if curr not in ptr:
			continue
		chck[curr] = 'found'
		derp = 0
		while curr in ptr:
			curr = ptr[curr]
			if curr in chck:
				derp = 1
				break
			chck[curr] = 'found'
		if derp == 0:
			count += 1
	return count

T = int(raw_input())



for i in xrange(T):

	N = int(raw_input())

	trainset = []
	read = raw_input()
	for k in read.split():
		trainset.append(k)
	starts = []
	mids = []
	ends = []
	flat = []

	ptr = {}

	for a in xrange(27):
		starts.append(0)
		mids.append(0)
		ends.append(0)
		flat.append(0)
	ans = 1
	for b in trainset:
		k = process(b)
		if k == -1:
			ans = "0"
			break
		if len(k) == 1:
			flat[ord(k[0])-ord('a')] += 1
		else:
			ptr[k[0]] = k[len(k)-1]
			for ind in xrange(len(k)):
				if ind == 0:
					starts[ord(k[ind]) - ord('a')] += 1
				elif ind == len(k)-1:
					ends[ord(k[ind]) - ord('a')] += 1
				else:
					mids[ord(k[ind]) - ord('a')] += 1

	if ans != "0":
		ans = 1
	for x in xrange(27):
		if starts[x] > 1 or ends[x] > 1:
			ans = "0"
			break
		if starts[x] + ends[x] + flat[x] > 0 and mids[x] > 0:
			ans = "0"
			break 	
		ans *= (factorial(flat[x]) % (MOD))
	
	totfree = 0
	for x in xrange(27):
		if starts[x] + ends[x] + mids[x] == 0 and flat[x] >0:
			totfree += 1

	if ans != '0':
		for let in string.lowercase:
			ans *= test(let, ptr)

	if ans == 0:
		ans = '0'
	
	if ans != '0':
		ans %= (MOD)

	if ans != '0':
		ans *= factorial(valid(ptr) + totfree)

	if ans != '0':
		ans %= (MOD)
	print "Case #" + str(i+1) + ": " + str(ans)
