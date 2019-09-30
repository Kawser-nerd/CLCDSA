A = [list(map(int,input().split())) for i in range(4)]
for i in range(4):
	for j in range(3):
		if A[i][j] == A[i][j+1] or A[j][i] == A[j+1][i]:
			print("CONTINUE")
			exit()
print("GAMEOVER")