N = int(input())
A, B = map(int, input().split())
if A == B:
    if N % (A+1) == 0:
        W = 0
    else:
        W = 1
else:
    if N <= A:
        W = 1
    else:
        if A < B:
            W = 0
        else:
            W = 1
print('Takahashi' if W else 'Aoki')