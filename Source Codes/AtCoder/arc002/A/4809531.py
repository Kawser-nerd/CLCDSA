y = int(input())

if y % 400 == 0:
    print('YES')
    exit()

if y % 100 == 0:
    print('NO')
    exit()

if y % 4 == 0:
    print('YES')
    exit()

print('NO')