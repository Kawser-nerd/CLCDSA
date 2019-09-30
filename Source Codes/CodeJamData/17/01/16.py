import sys
sys.setrecursionlimit(10000)

def solve(data,k):

	l = len(data)
	if l == k:
		if data == ["+"]*k:
			return 0
		elif data == ["-"]*k:
			return 1
		else:
			return -1

	if l < k:
		if data == ["+"]*l:
			return 0
		else:
			return -1
	
	flips = 0
	if data[0] == '-':
		for i in range(0,k):
			if data[i] == "+":
				data[i] = "-"
			else:
				data[i] = "+"

		flips = 1
		

	result = solve(data[1:],k)

	if result < 0:
		return -1

	return result + flips


t = int(raw_input())
for i in range(1, t + 1):
  n, m = [s for s in raw_input().split(" ")] 
  data = list(str(n))
  k = int(m)

  result = solve(data,k)
  if result == -1:
  	result = "IMPOSSIBLE"

  print("Case #{}: {}".format(i, result))

