#!python3

def solve(grid):
	grid2 = []
	for line in grid:
		lastch = None
		line2 = ''
		for ch in line:
			if ch != '?':
				line2 += ch
				lastch = ch
			elif lastch is not None:
				line2 += lastch
		# print(line2)
		if line2:
			grid2.append((line2[0]*(len(line)-len(line2))) + line2)
		elif grid2:
			grid2.append(grid2[-1])
	# print(grid2)
	return [grid2[0]]*(len(grid)-len(grid2)) + grid2

def main():
	ntest = int(input())
	for itest in range(ntest):
		R, C = map(int, input().strip().split(' '))
		grid = []
		for i in range(R):
			grid.append(input().strip())
		grid2 = solve(grid)
		print("Case #%d:" % (itest+1))
		for i in range(R):
			print(grid2[i])

if __name__ == '__main__':
	main()