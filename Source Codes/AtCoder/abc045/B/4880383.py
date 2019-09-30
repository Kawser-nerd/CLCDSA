A = list(input())
B = list(input())
C = list(input())

turn = A[0]

while True:
    if turn == 'a':
        if len(A) == 0:
            print('A')
            exit()
        turn = A[0]
        A.pop(0)

    if turn == 'b':
        if len(B) == 0:
            print('B')
            exit()
        turn = B[0]
        B.pop(0)

    if turn == 'c':
        if len(C) == 0:
            print('C')
            exit()
        turn = C[0]
        C.pop(0)