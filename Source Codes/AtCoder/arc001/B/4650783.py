A, B = [int(_) for _ in input().split()]

result = 0

if A > B:
    A, B = B, A

while A != B:
    if B >= A + 10:
        A += 10
    elif B == A + 9:
        A -= 1
    elif B == A + 8:
        A -= 1
    elif B == A + 7:
        A += 5
    elif B == A + 6:
        A += 5
    elif B == A + 5:
        A += 5
    elif B == A + 4:
        A -= 1
    elif B == A + 3:
        A += 1
    elif B == A + 2:
        A += 1
    elif B == A + 1:
        A += 1
    result += 1

print(result)