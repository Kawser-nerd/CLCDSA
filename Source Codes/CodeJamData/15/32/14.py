T = int(raw_input())

def parse(word, target):
	best = -1
	for i in xrange(1,len(word)+1):
#		print word, target, i
		if target[:i] == word[-i:]:
			best = i
#	print best
	if best == -1:
		return ""
	return target[:best]

def f(S, word, prob, K):
	start = {}
	start[("", 0)] = 1
	for i in xrange(S):
		newstart = {}
		for pair in start.keys():
			for letter in prob.keys():
				out = pair[0] + letter
				val = parse(out, word)
#				print out, letter
#				print word
#				print val
#				print
				loc_prob = (prob[letter])* start[pair]
#				if letter == "G":
#					print out, word, val
#				if loc_prob < 10e-35:
#					continue
				if val == word:
					loc_pair = (parse(out[1:], word), pair[1] + 1)
					if loc_pair in newstart:
						newstart[loc_pair] += loc_prob
					else:
						newstart[loc_pair] = loc_prob
				else:
					loc_pair = (parse(out, word), pair[1])
					if loc_pair in newstart:
						newstart[loc_pair] += loc_prob
					else:
						newstart[loc_pair] = loc_prob
		start = newstart
#		print start
	count = 0
	mymax = 0
	for thing in newstart.keys():
		prob = newstart[thing]
		count += prob * thing[1]
		mymax = max(mymax, thing[1])
	return mymax - count

def doprob():
	read = [int(k) for k in raw_input().split()]
	K = read[0]
	L = read[1]
	S = read[2]
	keyboard = list(raw_input())
	word = raw_input()
	prob = {}
	for x in keyboard:
		if x in prob:
			prob[x] += 1.0/K
		else:
			prob[x] = 1.0/K
	for x in word:
		if x not in keyboard:
			break
	else:
		return f(S, word, prob, K)
	return str(0.0)

for qq in range(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())