N = int(input())
A = list(map(int, input().split()))

AA = [0]
AA.extend(A)
AA.append(0)

Adif1 = []

for i in range(1, N + 2):
	x = abs(AA[i] - AA[i - 1])
	Adif1.append(x)

s = sum(Adif1)

Adif2 = []

for i in range(2, N + 2):
	x = abs(AA[i] - AA[i - 2])
	Adif2.append(x)

for i in range(N):
	print(s + Adif2[i] - Adif1[i] - Adif1[i + 1])