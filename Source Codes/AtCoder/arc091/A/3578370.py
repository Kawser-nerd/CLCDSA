N,M = map(int,input().split())
if N == 2 or M == 2:
    print(0)
elif N == 1 or M == 1:
    if N*M == 1:
        print(1)
    else:
        print(M*N - 2)
else:
    print( (N-2) * (M-2) )