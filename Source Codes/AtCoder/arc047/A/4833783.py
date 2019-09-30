n,l = map(int,input().split())
s = input()
tmp = 1
cnt = 0
for i in range(len(s)):
	if s[i] == '+':
		tmp += 1
		if tmp > l:
			cnt += 1
			tmp = 1
	else:
		tmp -= 1
print(cnt)