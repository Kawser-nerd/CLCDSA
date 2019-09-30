import sys

class Image():
	def __init__(self, height_, width_, matrix_):
		self.width = width_
		self.height = height_
		self.matrix = matrix_

		self.num_blue = 0
		for i in range(height_):
			for j in range(width_):
				if matrix_[i][j] == '#':
					self.num_blue += 1

	def place_tile(self, i, j):
		if i >= self.height - 1 or j >= self.width - 1:
			return False
		if self.matrix[i][j] == '#' and self.matrix[i][j+1] == '#' and 		   self.matrix[i+1][j] == '#' and self.matrix[i][j+1] == '#':
			self.matrix[i][j] = '/'
			self.matrix[i][j+1] = '\\'
			self.matrix[i+1][j] = '\\'
			self.matrix[i+1][j+1] = '/'
			self.num_blue -= 4
	def __str__(self):
		return '\n'.join([''.join(row) for row in self.matrix])

def do_case(r, c, matrix):
	image = Image(r, c, matrix)
	if image.num_blue % 4 != 0:
		return None
	for i in range(r):
		for j in range(c):
			image.place_tile(i, j)
			if image.num_blue % 4 != 0:
				return None
	if image.num_blue == 0:
		return image
	else:
		return None
	


in_, out_f= sys.argv[1], sys.argv[1]+".out"
out = open(out_f, 'w')
with open(in_, 'r') as file:
	num = 1
	num_cases = int(file.next().rstrip())
	for num in range(1, num_cases+1):
		r, c = map(int, file.next().rstrip().split(' '))
		image = [[None for j in range(c)] for i in range(r)]
		for i in range(r):
			row = file.next().rstrip()
			for j,t in enumerate(row):
				image[i][j] = t
		ret = do_case(r, c, image)
		out.write("Case #%d:\n" % (num))
		print "Case #%d:\n" % (num),
		if ret is None:
			out.write("Impossible\n")
			print "Impossible"
		else:
			print ret
			out.write("%s\n" % (ret))


