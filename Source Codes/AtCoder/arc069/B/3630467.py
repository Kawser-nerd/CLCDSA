n = int(input())
s = input()
for c in ['SS','SW','WS','WW']:
    for d in range(1,n-1):
        if c[d] == 'S':
            if s[d] == 'o':
                c += c[d-1]
            elif c[d-1] == 'S':
                c += 'W'
            else:
                c += 'S'
        else:
            if s[d] == 'x':
                c += c[d-1]
            elif c[d-1] == 'S':
                c += 'W'
            else:
                c += 'S'
    res = ''
    for i in range(len(c)):
        if c[i-1] == c[(i+1)-len(c)]:
            if c[i] == 'S':
                res += 'o'
            else:
                res += 'x'
        else:
            if c[i] == 'S':
                res += 'x'
            else:
                res += 'o'
    if res == s:
        print(c)
        exit()
print(-1)