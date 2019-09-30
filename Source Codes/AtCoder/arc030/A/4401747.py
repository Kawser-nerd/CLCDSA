n = int(input())
k = int(input())

tmp = 0
for i in range(10 ** 5):
    n = n - 2
    tmp += 1
    if n < 0:
        print('NO')
        break
    if tmp == k:
        print('YES')
        break