import math

A = int(input())
B = int(input())
#A = math.log10(A)
#B = math.log10(B)

if A > B:
    print('GREATER')
elif A < B:
    print('LESS')
else:
    print('EQUAL')