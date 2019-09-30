A, B, C = map(int, input().split())
p = A + B
m = A - B

if C == p == m:
    print('?')
elif C != p and C != m:
    print('!')
elif C == p:
    print('+')
elif C == m:
    print('-')