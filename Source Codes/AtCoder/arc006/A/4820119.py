E = list(map(int,input().split()))
b = int(input())
L = list(map(int,input().split()))
cnt = 0
bonus = 0
for l in L:
	if l in E:
		cnt += 1
	elif l == b:
		bonus += 1
if cnt == 6:
	print(1)
elif cnt == 5 and bonus == 1:
	print(2)
elif cnt == 5:
	print(3)
elif cnt == 4:
	print(4)
elif cnt == 3:
	print(5)
else:
	print(0)