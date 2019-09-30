s = input()
t = ''
#[chr(i) for i in range(97, 97+26)]
cur = s[0]
cnt = 0
for i in range(len(s)):
    if cur == s[i]:
        cnt += 1
    else:
        t += '{}{}'.format(cur, cnt)
        cur = s[i]
        cnt = 1
t += '{}{}'.format(cur, cnt)
print(t)