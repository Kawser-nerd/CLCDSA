n = int(input())
num = []
for i in range(1,555556):
	if len(set(str(i))) == 1:
		num.append(i)
print(num[n-1])