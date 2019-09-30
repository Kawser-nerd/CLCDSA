s = input()
if s[0] == '0':
    s = '1' + s

l = len(s)
sep = l
for i in range(1, l):
    if s[i] != '0':
        sep = i
        break

a = []
a.append(int(s[0:sep]))
s = s[sep:l]
l = len(s)
if l == 0:
    print(a[0], 1)
    exit()

if a[0] >= int(s):
    b = int(s)
    sa = str(a[0])
    la = len(sa)
    lb = len(s)
    if la > lb and sa[0:lb] == s[0:lb]:
        print(a[0], 1)
        exit()

    while a[0] >= b:
        b *= 10

    print(a[0], b - a[0])
    exit()

def check(s, t):
    if s[0] == '0' or t[0] == '0':
        return False

    ls = len(s)
    lt = len(t)
    l = min(ls, lt)
    if s[0:l] == t[0:l]:
        return True
    else:
        return False

for i in range(1, l):
    b = [a[0]]
    b.append(int(s[0:i]))
    r = b[1] - b[0]
    if r <= 0:
        continue

    t = s[i:l]
    while True:
        b.append(b[-1] + r)
        u = str(b[-1])
        if not check(t, u):
            break

        lt = len(t)
        lu = len(u)
        if lt <= lu:
            print(b[0], r)
            exit()

        t = t[lu:lt]

print(a[0], int(s) - a[0])