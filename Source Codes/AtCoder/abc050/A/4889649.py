A, op, B = input().split()
A, B = map(int, [A, B])
if op == "+":
    print(A+B)
else:
    print(A-B)