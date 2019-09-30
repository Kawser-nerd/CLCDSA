n = int(input())
s = list(input())

cnt = 0
res = ''
for i in range(n):
    if s[i] == '(':
        cnt += 1
    else:
        if cnt > 0:
            cnt -= 1
        else:
            res = '('+res
    res += s[i]

for j in range(cnt):
    res += ')'
print(res)