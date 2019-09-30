import sys
import re

def solve( dic, words ):
	ret = []
	for word in words:
		modified = ""
		paropen = False
		for char in word:
			if char == ")":
				paropen = False
				modified = modified[:-1] + char
			elif char == "(":
				paropen = True
				modified += char
			else:
				if paropen:
					modified += char+"|"
				else:
					modified += char
		word = modified
		
		pattern = re.compile(word)
		cnt = 0
		for dic_word in dic:
			if pattern.match(dic_word) is not None:
				cnt += 1
		ret.append(cnt)

	return ret
	
if __name__ == "__main__":
	infile = open( sys.argv[1], "r" )
	outfile = open( "resultA.txt", "w" )
	
	input = [ int(item) for item in infile.readline().strip().split(" ")	if item != "" ]
	L, D, N = input[0], input[1], input[2]
	
	dic = []
	for i in range(D):
		dic.append( infile.readline().strip() )
	
	words = []
	for i in range(N):
		words.append( infile.readline().strip() )
	
	solution = solve( dic, words )
	
	for i in range( len(solution) ):
		outfile.write( "Case #%d: %d\n" % (i+1, solution[i]) )
		
	infile.close()
	outfile.close()
