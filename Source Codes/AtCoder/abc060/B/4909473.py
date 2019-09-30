A, B, C = map(int, input().split())
R = {i: False for i in range(B)}
X = 0
while True:
    X += A
    r = X % B
    if r == C:
        print("YES")
        exit()
    if R[r]:
        print("NO")
        exit()
    R[r] = True