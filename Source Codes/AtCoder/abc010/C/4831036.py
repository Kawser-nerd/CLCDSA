import math

tx_a, ty_a, tx_b, ty_b, T, V = map(int, input().rstrip().split())
n = int(input())

possibility = T * V
flg = 0

for i in range(n):
    x, y = map(int, input().rstrip().split())
    if flg == 0:
        d_girl = math.sqrt((x-tx_a)**2 + (y-ty_a)**2) + \
            math.sqrt((x-tx_b)**2 + (y-ty_b)**2)
        if possibility >= d_girl:
            flg = 1
    else:
        pass

if flg == 0:
    print('NO')
else:
    print('YES')