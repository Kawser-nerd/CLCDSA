s = input()

left = 0
right = 0
flag = True
for i in range(0,len(s)):
    if s[i] == "A" and flag:
        left = i
        flag = False
    if s[i] == "Z":
        right = i

print(right  - left + 1)