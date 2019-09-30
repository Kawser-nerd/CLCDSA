S = input()

ans = "yes"
for i in range(len(S)):
	if S.count(S[i:i+1]) > 1:
		ans = "no"
		break

print(ans)