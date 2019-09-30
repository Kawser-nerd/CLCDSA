# seishin.py
A = int(input())
A2 = A**2
B = A + 1
B2 = B**2

A0 = str(A2)
B0 = str(B2)
L = len(B0)
assert len(A0) + 1 >= L
if len(A0) < L:
    A0 = "0" + A0
if L % 2:
    A0 = "0" + A0
    B0 = "0" + B0
L = len(A0)

ans = int(A0)
for i in range(1, L, 2):
    a = int(A0[:i+1])
    b = int(B0[:i+1])
    # ??[a, b) ???????N????
    if int("0"+A0[i+1:]) == 0:
        if int("0"+B0[i+1:]) > 0:
            if a <= b:
                ans = a
                break
        else:
            # b = "~~~~~.000000000"?????
            if a < b:
                ans = a
                break
    if a == 0:
        continue

    if int("0"+B0[i+1:]) > 0:
        if a+1 <= b:
            ans = a+1
            break
    else:
        # b = "~~~~~.000000000"?????
        if a+1 < b:
            ans = a+1
            break
print(ans)