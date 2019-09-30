n = int(input())
lis = [list(input()) for i in range(n)]
cou = 0
for k in range(n):
	if "." in lis[k]:
		if k != n-1:
			num = 0
			for m in range(n):
				if lis[k][m] == ".":
					num = m
			lis[k+1][num:] = "o"*len(lis[k+1][num:])
		cou += 1
print(cou)