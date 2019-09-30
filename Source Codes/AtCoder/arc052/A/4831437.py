s = input()
num = "1234567890"
res = ""
for i in s:
	if i in num:
		res += i
print(res)