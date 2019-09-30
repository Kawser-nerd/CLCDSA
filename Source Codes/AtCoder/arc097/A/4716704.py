s = input()
N = len(s)
K = int(input())
L = []
for i in range(N):
	for j in range(5):
		if i + j < N:
			L.append(s[i:i + j + 1])

L = sorted(L)

sub = ""
x = 0
for i in L:
	if sub != i:
		sub = i
		x += 1
	
	if x == K:
		print(sub)
		break