from sys import stdin
input = stdin.readline
w = input().rstrip()
dic = {}
for i in w:
	if not i in dic:
		dic[i] = 1
	else:
		dic[i] += 1
for word in dic:
	if dic[word]%2 != 0:
		print("No")
		break
else:
	print("Yes")