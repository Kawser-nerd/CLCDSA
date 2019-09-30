s = list(set(list(input())))
s.sort()
if len(s) == 4:
    print('Yes')
elif len(s) == 2:
    if s[0] + s[1] == 'NS' or s[0] + s[1] == 'EW':
        print('Yes')
    else:
        print('No')
else:
    print('No')