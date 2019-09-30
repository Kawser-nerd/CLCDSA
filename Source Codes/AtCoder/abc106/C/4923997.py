s = input()
k = int(input())
i = 0

while s[i] == "1":
	i += 1
	if i > len(s) - 1:
		break

if k <= len(s) and i >= k:
	print(1)
else:
	print(s[i])