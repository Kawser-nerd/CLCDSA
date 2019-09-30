x = input()
s = []
for a in x:
    if len(s) == 0:
        s.append(a)
    else:
        t = s.pop()
        if t != 'S' or a != 'T':
            s.append(t)
            s.append(a)
print(len(s))