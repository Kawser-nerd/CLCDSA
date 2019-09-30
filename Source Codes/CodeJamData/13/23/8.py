import os

input = "test.in"
input = "C-small-attempt0.in";
#input = "a-large.in";

output = input.replace(".in", ".out")

in_f = open(input, "r")

dict = set([a[:-1] for a in open("dict.txt", "rb").readlines()])
small_dict = []

def get_line():
	return in_f.readline()[:-1]
	
def get_int():
	return int(get_line())

def get_sep():
	return get_line().split(" ")
	
def get_sep_int():
	return [int(i) for i in get_sep()]	
	
	
lets = [chr(i) for i in xrange(ord('a'), ord('z') + 1)]
sols = {}

def get_min_ops(s, min_pos):
	#print "XXXXX"
	if s in dict:
	#	print "s in dict", s
		return 0
	if s == "":
	#	print "empty", s
		return 0
	if (s, min_pos) in sols:
	#	print "in sols"
		return sols[(s,min_pos)]
		
	#if len(s) != 3:
	#	return 100000
	
	#print "begin", s, min_pos
	min_ops = 1000000
	for word_len in xrange(1, min(11, len(s) + 1)):
		#print word_len, s
		word = s[:word_len]
		#print word
		#print "word_len", word_len
		if word in dict:
	#		print "in dict", word, word_len, s[word_len:]
			min_ops = min(min_ops, get_min_ops(s[word_len:], max(0, min_pos - word_len)))				
		else:
			#print "not in dict", word
			for let_chg1 in xrange(min_pos, word_len):
				for let1 in lets:
					sep_word = [j for j in s[:word_len]]
					sep_word[let_chg1] = let1
					fixed_word = "".join(sep_word)
					if not fixed_word in dict:
						continue				
					min_ops = min(min_ops, get_min_ops(s[word_len:], max(0, 4 - (word_len - 1 - let_chg1))) + 1)
					
			if word_len < 5:
				continue
			found = False
			for let_chg1 in xrange(min_pos, word_len):
				for let_chg2 in xrange(let_chg1 + 5, word_len):
					if found:
						break
					for let1 in lets:					
						if found:
							break;
						for let2 in lets:
							sep_word = [j for j in s[:word_len]]
							sep_word[let_chg1] = let1
							sep_word[let_chg2] = let2
							fixed_word = "".join(sep_word)
							if not fixed_word in dict:
								continue
							min_ops = min(min_ops, get_min_ops(s[word_len:], max(0, 4 - (word_len - 1 - let_chg2))) + 2)
							found = True
							break
					
	
	sols[(s, min_pos)] =  min_ops
	#print s, min_pos, min_ops
	return min_ops

def get_solution_str(s):
	'''
	sep_s = [i for i in s]
	while len(sep_s) > 0:
		for word_len in xrange(1,11):
			for pos1 in xrange(word_len):
				for let1 in lets:
					part = sep_s[:word_len]
					part[pos1] = let1
					
	
	'''
	
	return get_min_ops(s, 0)

num_cases = get_int()
out = open(output, "w")

for cur_case in xrange(1, num_cases + 1):
	s = get_line()
	print cur_case
		
	sol = get_solution_str(s)
	
	out.write("Case #%d: %s\n" %(cur_case, sol))