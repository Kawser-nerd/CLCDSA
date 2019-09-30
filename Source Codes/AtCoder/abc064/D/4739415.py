n = int(input())
s = list(input())
left = 0
right = 0
i = 0
while i < len(s):
    if s[i] == "(":
        left += 1
    else:
        right += 1
    if left < right:
        s.insert(0,"(")
        left += 1
        i += 1
    i += 1
for i in range(left-right):
    s.append(")")
for i in range(len(s)):
    if i != len(s)-1:
        print(s[i],end="")
    else:
        print(s[i])