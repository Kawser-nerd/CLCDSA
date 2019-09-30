A, B, C = map(int, input().split())

if A <= B:
    print(C // A)
else:
    print(C // B)