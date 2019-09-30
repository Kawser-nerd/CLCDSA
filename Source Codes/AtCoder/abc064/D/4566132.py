"""
"""

n = int(input())
s = input()

# ?????
tmp, cnt = 0, 0

for i in s:
    if i == "(":
        tmp -= 1
    else:
        tmp += 1
    cnt = max(cnt, tmp)

ans = "(" * cnt + s

# ?????
tmp, cnt = 0, 0
for i in s[::-1]:
    if i == "(":
        tmp += 1
    else:
        tmp -= 1
    cnt = max(cnt, tmp)

ans += ")" * cnt
print (ans)