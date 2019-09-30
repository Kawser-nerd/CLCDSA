S = input()
K = int(input())

oneRow = 0

for i in range(0,len(S)):
	if S[i] == '1':
		oneRow += 1
	else:
		break


if K <= oneRow:
	print(1)
else:
	print(int(S[oneRow]))