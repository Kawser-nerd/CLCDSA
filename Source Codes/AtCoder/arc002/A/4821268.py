Y = int(input())

if Y % 400 == 0:
    print('YES')
    exit()
if Y % 100 == 0:
    print('NO')
    exit()
if Y % 4 == 0:
    print('YES')
    exit()

print('NO')