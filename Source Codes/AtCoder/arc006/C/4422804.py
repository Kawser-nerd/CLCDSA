import copy
N = int(input())
w = []
for i in range(N):
	w.append(int(input()))
bottom = [0]
for i in range(N):
	if max(bottom) < w[i]:
		bottom.append(w[i])
	else:
		temp_bottom = copy.copy(bottom)
		judge = 0
		while judge == 0:
			if min(temp_bottom) < w[i]:
				temp_bottom.remove(min(temp_bottom))
			else:
				minmax = min(temp_bottom)
				judge = 1
		bottom.remove(minmax)
		bottom.append(w[i])
print(len(bottom) - 1)