abcd = input()
a = int(abcd[0])
b = int(abcd[1])
c = int(abcd[2])
d = int(abcd[3])

if a + b + c + d == 7:
    print(a, '+', b, '+', c, '+', d, '=7', sep='')
elif a + b + c - d == 7:
    print(a, '+', b, '+', c, '-', d, '=7', sep='')
elif a + b - c + d == 7:
    print(a, '+', b, '-', c, '+', d, '=7', sep='')
elif a + b - c - d == 7:
    print(a, '+', b, '-', c, '-', d, '=7', sep='')
elif a - b + c + d == 7:
    print(a, '-', b, '+', c, '+', d, '=7', sep='')
elif a - b + c - d == 7:
    print(a, '-', b, '+', c, '-', d, '=7', sep='')
elif a - b - c + d == 7:
    print(a, '-', b, '-', c, '+', d, '=7', sep='')
elif a - b - c - d == 7:
    print(a, '-', b, '-', c, '-', d, '=7', sep='')