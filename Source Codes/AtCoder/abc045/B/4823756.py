def selection(X, A, B, C):
    if X == 'a':
        if len(A) == 0:
            print('A')
            return
        else:
            Y = A.pop(0)
    if X == 'b':
        if len(B) == 0:
            print('B')
            return
        else:
            Y = B.pop(0)
    if X == 'c':
        if len(C) == 0:
            print('C')
            return
        else:
            Y = C.pop(0)
    selection(Y, A, B, C)

def main():
    Sa = list(input())
    Sb = list(input())
    Sc = list(input())
    selection('a', Sa, Sb, Sc)

main()