N = int(input())
As = list(map(int, input().split()))

maxA = max(As)
minA = min(As)

if minA >= 0:
    # ??????0?????
    flg = 'GE'
    print(N-1)
elif maxA <= 0:
    # ??????0?????
    flg = 'LE'
    print(N-1)
else:
    if -minA <= maxA:
        flg = 'GE'
        print(2*N-1)
        # ??????0?????
        iMax = As.index(maxA) + 1
        for i in range(1, N+1):
            print(iMax, i)
    else:
        flg = 'LE'
        print(2*N-1)
        # ??????0?????
        iMin = As.index(minA) + 1
        for i in range(1, N+1):
            print(iMin, i)

if flg == 'GE':
    # ??????????
    for i in range(1, N):
        print(i, i+1)
else:
    # ??????????
    for i in reversed(range(1, N)):
        print(i+1, i)