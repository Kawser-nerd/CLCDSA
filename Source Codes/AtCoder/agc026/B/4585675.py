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
    else:
        g = gcd(B, D)
        if B - g + (A % g) > C:
            print('No')
        else:
            print('Yes')