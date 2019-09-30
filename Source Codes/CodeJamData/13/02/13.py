class Lawn:
	def __init__(self, rows, cols, board):
		self.rows = rows
		self.cols = cols
		self.board = board
		self.cleared = None
	
	def _can_square_be_trimmed(self, r, c):
		h = board[r][c]
		#check row:
		if all([board[r][i] <= h for i in xrange(self.cols)]):
			for i in xrange(self.cols):
				self.cleared[r][i] = True
				return True
		#check col
		if all([board[i][c] <= h for i in xrange(self.rows)]):
			for i in xrange(self.rows):
				self.cleared[i][c] = True
				return True
	
	def can_be_trimmed(self):
		self.cleared = []
		for r in xrange(self.rows):
			self.cleared.append( [False]*self.cols )
		
		for r in xrange(self.rows):
			for c in xrange(self.cols):
				if self.cleared[r][c]:
					continue
				if not self._can_square_be_trimmed(r, c):
					return False
		return True


def read_numbers():
	return map(int, raw_input().split(" "))
	
cases_count = input()
for case in xrange(cases_count):
	lines,cols = read_numbers()
	board = []
	for line in xrange(lines):
		board.append(read_numbers())
	lawn = Lawn(lines, cols, board)
	
	result = lawn.can_be_trimmed()
	
	if result:
		result = "YES"
	else:
		result = "NO"
	print "Case #%d: %s" % (case+1, result)
