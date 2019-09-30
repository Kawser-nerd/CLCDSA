N = int(input())
S = input()
tmp = 'b'
flg = 1
count = 0
if N % 2 == 0:
    print(-1)
else:
    while len(tmp) < N:
        if flg == 1:
            tmp = 'a' + tmp + 'c'
            flg = 2
        elif flg == 2:
            tmp = 'c' + tmp + 'a'
            flg = 3
        elif flg == 3:
            tmp = 'b' + tmp + 'b'
            flg = 1
        count += 1
    if S == tmp:
        print(count)
    else:
        print(-1)