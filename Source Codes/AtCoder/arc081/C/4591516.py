from collections import Counter
s = input()
def num(letter):
	return ord(letter) - 97
def let(number):
	return chr(number + 97)

ok = 0
ng = len(s)
used = [False] * 26
tmp = 0
cnt = 0
for i in range(len(s)):
	if used[num(s[i])] == False:
		used[num(s[i])] = True
		tmp += 1
	if tmp == 26:
		cnt += 1
		tmp = 0
		used = [False] * 26

prm = cnt+1

if prm == 1:
	for j in range(26):
		if used[j] == False:
			print(let(j))
			break
else:
	d = []
	used = [False] * 26
	tmp = 0
	for i in range(len(s)-1, -1, -1):
		if used[num(s[i])] == False:
			used[num(s[i])] = True
			tmp += 1
		if tmp == 26:
			tmp = 0
			used = [False] * 26
			d.append(i)
	d = d[::-1]
	#print(d)
	ans = ""
	cnt = 0
	i = 0
	skip = False
	used = [False] * 26
	for i in range(len(s)):
		if cnt < prm-1:
			if i == d[cnt]:
				for j in range(26):
					if used[j] == False:
						ans += let(j)
						break
				used = [False] * 26
				cnt += 1
				skip = True
				
		if skip:
			if s[i] == ans[-1]:
				#print(i)
				skip = False
			continue

		if used[num(s[i])] == False:
			used[num(s[i])] = True

	#print(used)
	for j in range(26):
		if used[j] == False:
			ans += let(j)
			break
	print(ans)