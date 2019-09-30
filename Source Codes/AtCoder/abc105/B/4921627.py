N = int(input())
flg = 0
for i in range(N//4 + 1):
    for j in range(N//7 + 1):
        if N == 4 * i + 7 * j:
            flg = 1
if flg == 1:
    print('Yes')
else:
    print('No')