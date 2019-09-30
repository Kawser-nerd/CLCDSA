N,A,B = map(int,input().split())
if A > B:
    print(0)
    exit()
if N == 1 and A != B:
    print(0)
    exit()
elif N == 1 and A == B:
    print(1)
    exit()


print( (B*(N-1) + A) - (A*(N-1) +B) + 1 )