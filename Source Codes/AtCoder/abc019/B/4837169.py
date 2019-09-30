s = input()
s = s + "X"
temp = s[0]
a = []
cnt = 1
for i in range(1,len(s)):
    if temp!=s[i]:
        a.append(str(temp)+str(cnt))
        cnt = 1
        temp = s[i]
    else:
        cnt += 1
print("".join(a))