a, b, c = map(int, input().split())
if a + b == c:
    if a - b == c:
        print('?')
    else:
        print('+')
elif a - b == c:
    if a + b == c:
        print('?')
    else:
        print('-')
else:
    print('!')