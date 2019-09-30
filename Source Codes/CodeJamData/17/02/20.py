import sys

def solve(data):

	if data == [0]:
		return [0]

	for i in range(len(data)-1,0,-1):
		if data[i] < data[i-1]:
			data[i-1] = data[i-1] - 1
			for j in range(i, len(data)):
				data[j] = 9

	if(data[0] == 0):
		del data[0]

	return data


t = int(raw_input())
for i in range(1, t + 1):
  n = raw_input()
  data = [int(a) for a in list(str(n))]

  result = solve(data)

  print("Case #{}: {}".format(i, "".join([str(el) for el in result])))