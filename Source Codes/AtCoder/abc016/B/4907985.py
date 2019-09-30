A, B, C = map(int, input().split())
if A+B == A-B == C:
    print('?')
elif A + B == C:
    print('+')
elif A - B == C:
    print('-')
else:
    print('!')