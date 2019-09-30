import sys

keyword = "welcome to code jam"

def solve(text):
	dynamic = []
	
	solution = 0

	for i in range( len(text) ):
		cur = []
		dynamic.append( cur )
		if text[i] == keyword[0]:
			cur.append(1)
		else:
			cur.append(0)
		
		for j in range( 1, len(keyword) ):
			cur.append(0)
			if text[i] != keyword[j]:
				continue
			for k in range( 0, i ):
				if text[k] != keyword[j-1]:
					continue
				cur[j] = (cur[j] + dynamic[k][j-1]) % 10000

		solution = (solution + cur[ len(keyword)-1 ]) % 10000
		
	return solution
		
if __name__ == "__main__":
	infile = open( sys.argv[1], "r" )
	outfile = open( "resultC.txt", "w" )
	
	N = int( infile.readline().strip() )
	for case in range(N):
		text = infile.readline().strip()
		outfile.write( "Case #%d: %04d\n" % (case+1, solve(text)) )
	
	infile.close()
	outfile.close()
