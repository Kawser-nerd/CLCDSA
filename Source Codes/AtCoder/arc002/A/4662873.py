y = int(input())
if y % 400 == 0:
    print('YES')
elif y % 100 == 0:
    print('NO')
elif y % 4 == 0:
    print('YES')
else:
    print('NO')