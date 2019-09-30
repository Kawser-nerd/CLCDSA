#15
a, b, c = map(int, input().split())
if b==0 and a==c:
    print('?')
elif a+b==c:
    print('+')
elif a-b==c:
    print('-')
else:
    print('!')