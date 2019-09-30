H1, W1 = map(int, input().split())
H2, W2 = map(int, input().split())

flag = False

if H1==H2:
    flag=True
if H1==W2:
    flag=True
if W1==H2:
    flag=True
if W1==W2:
    flag=True

if flag:
    print('YES')
else:
    print('NO')