N = int(input())
S = input()
res = ''
for s in S:
    if res == '':
        res += s
    elif res == s:
        res = ''
    elif len(res) == 1:
        res = ''.join(sorted(res + s))
    elif len(res) == 2 and s in res:
        res = res.replace(s, '')
    elif len(res) == 2:
        res = 'RGB'
    else:
        res = res.replace(s, '')
print(len(res))