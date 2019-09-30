s = input()
cnt = 0
temp = 0
for i in range(len(s)):
    if s[i]=="+":
        t = s[temp:i]
        if t.find("0")==-1:
            cnt += 1
        temp = i+1
if s[temp:].find("0")==-1:
    cnt += 1
print(cnt)