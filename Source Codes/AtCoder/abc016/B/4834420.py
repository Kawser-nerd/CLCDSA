A,B,C=map(int, input().split(' '))
if A+B==C:
    if A-B!=C:
        print('+')
    else:
        print('?')
elif A+B!=C:
    if A-B==C:
        print('-')
    else:
        print('!')