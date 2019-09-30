A, B, C = map(int, input().split())
ApB = A+B == C
AmB = A-B == C
if ApB and AmB:
    print('?')
elif ApB:
    print('+')
elif AmB:
    print('-')
else:
    print('!')