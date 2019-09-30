s = list(input())
N = len(s)
judge = "balanced"
for i in range(N - 1):
	if s[i] == s[i + 1]:
		print(i + 1, i + 2)
		judge = "unbalanced"
		break

if judge == "balanced":
	for i in range(N - 2):
		if s[i] == s[i + 2]:
			print(i + 1, i + 3)
			judge = "unbalanced"
			break
			
if judge == "balanced":
	print(-1, -1)