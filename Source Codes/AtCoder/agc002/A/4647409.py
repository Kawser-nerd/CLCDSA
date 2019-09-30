a, b = list(map(int, input().split()))

if a > 0 and b > 0:
    print('Positive')
elif a < 0 and b < 0:
    if (a-b+1) % 2:
        print('Negative')
    else:
        print('Positive')
else:
    print('Zero')