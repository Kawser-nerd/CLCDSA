def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

T = int(input())

for _ in range(T):
    A, B, C, D = map(int, input().split())

    if B > A:
        print('No')
    elif B > D:
        print('No')
    elif C >= B:
        print('Yes')
    elif A % B > C:
        print('No')
    else:
        s = A % B
        g = gcd(B, D)
        if s + (B-1-s)//g*g > C:
            print('No')
        else:
            print('Yes')