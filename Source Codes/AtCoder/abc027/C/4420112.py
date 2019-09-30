n = int(input())

cnt = 0
m = n
while m > 1:
    m //= 2
    cnt += 1

taka = True
m = 1
while m <= n:
    if taka ^ (cnt % 2 == 0):
        m = 2 * m
    else:
        m = 2 * m + 1
    taka = not taka

if taka:
    print('Takahashi')
else:
    print('Aoki')