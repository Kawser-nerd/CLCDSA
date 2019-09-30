n,a,b = map(int,input().split())
turn = 1
while True:
    if turn == 1:
        if n > a:
            n -= a
            turn *= -1
        else:
            print("Ant")
            exit()
    else:
        if n > b:
            n -= b
            turn *= -1
        else:
            print("Bug")
            exit()