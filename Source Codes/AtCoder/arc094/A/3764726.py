A, B, C = sorted(map(int, input().split()))

ret = 0

m = A % 2 + B % 2 + C % 2

if m == 3 or m == 0:
    pass
else:
    ret += 1
    if m == 2:
        if A % 2 == 0:
            B += 1
            C += 1
        elif B % 2 == 0:
            A += 1
            C += 1
        else:
            A += 1
            B += 1
    else:
        if A % 2 == 1:
            B += 1
            C += 1
        elif B % 2 == 1:
            A += 1
            C += 1
        else:
            A += 1
            B += 1

print(ret + (C - B) // 2 + (C - A) // 2)