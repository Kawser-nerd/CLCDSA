a, b, c = map(int, input().split(' '))

flag = False
for i in range(b):
    if a * i % b == c:
        flag = True
if flag:
    print('YES')
else:
    print('NO')