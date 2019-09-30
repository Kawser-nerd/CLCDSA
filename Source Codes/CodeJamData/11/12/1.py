import sys
import string

input = open("test.in")
output = open("test.out", "w")

def reveal(word, mask, letter):
	res = ""
	for i in range(len(word)):
		if word[i] == letter:
			res += letter
		else:
			res += mask[i]
	return res
			
def init_mask(word):
	mask = ""
	for i in range(len(word)):
		mask += "?"
	return mask
			
def solve(words, seq):
	sets = {}
	cnts = {}
	masks = {}
	for i in range(len(words)):
		mask = init_mask(words[i])
		masks[i] = mask
		cnts[i] = 0
		if mask in sets:
			sets[mask].append(i)
		else:
			sets[mask] = [i]
	
	for p in range(len(seq)):
		next_sets = {}	
		for (mask, word_idxs) in sets.items():
			if len(word_idxs) == 1:
				#print(words[word_idxs[0]] + ": " + str(cnts[word_idxs[0]]))
				continue
		
			flag = False
			for idx in word_idxs:
				if words[idx].find(seq[p]) != -1:
					flag = True
					break
			if flag:
				for idx in word_idxs:
					if words[idx].find(seq[p]) == -1:
						cnts[idx] += 1
					mask = reveal(words[idx], masks[idx], seq[p])
					#print(words[idx] + ": " + masks[idx] + " -> " + mask)
					masks[idx] = mask

			for idx in word_idxs:
				if masks[idx] in next_sets:
					next_sets[masks[idx]].append(idx)
				else:
					next_sets[masks[idx]] = [idx]
					
		sets = next_sets			

	best = 0
	for i in range(1,len(words)):
		if cnts[i] > cnts[best]:
			best = i
	
	return words[best]
	
		
	
lines = input.read().splitlines()
num_tests = int(lines[0])
line_i = 0
for t in range(num_tests):
	line_i += 1
	line = lines[line_i]
	prms = line.split(" ")
	n = int(prms[0])
	m = int(prms[1])
	
	words = []
	for i in range(n):
		line_i += 1
		word = lines[line_i]
		words.append(word)
	#print(words)
		
	ans = []
	for j in range(m):
		line_i += 1
		seq = lines[line_i]
		ans.append(solve(words, seq))
	
	output.write("Case #" + str(t+1) + ": " + (" ".join(ans)) + "\n")		
	

	