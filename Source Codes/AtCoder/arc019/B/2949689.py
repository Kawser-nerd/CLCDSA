S = list(input())
N = len(S)

if N == 1:
	print(0)
elif N%2 == 0:
	cnt = 0
	for i in range(N//2):
		if S[i] != S[N-i-1]:
			cnt += 1
	if cnt == 1:
		print(25*N-2)
	else:
		print(25*N)
elif N%2 == 1:
	cnt = 0
	for i in range(N//2):
		if S[i] != S[N-i-1]:
			cnt += 1
	if cnt == 0:
		print(25*(N-1))
	elif cnt == 1:
		print(25*N-2)
	else:
		print(25*N)