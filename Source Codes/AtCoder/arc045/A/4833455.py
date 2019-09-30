S = list(input().split())
ans = []
for s in S:
	if s == "Left":
		ans.append('<')
	elif s == "Right":
		ans.append('>')
	else:
		ans.append('A')
print(*ans)