n,a,b = map(int,input().split())
M = [1]+[0]*n+[1]
a -= 1
b -= 1
M[a] = 1
M[b] = 1
turn = 1
while True:
    if turn == 1:
        if M[a+1] == 1 and M[a-1] == 0:
            M[a-1] = 1
            M[a] = 0
            a -= 1
            turn *= -1
        elif M[a-1] == 1 and M[a+1] == 0:
            M[a+1] = 1
            M[a] = 0
            a += 1
            turn *= -1
        elif M[a-1] == 0 and M[a+1] == 0:
            M[a+1] = 1
            M[a] = 0
            a += 1
            turn *= -1
        else:
            print("Borys")
            exit()
    else:
        if M[b+1] == 1 and M[b-1] == 0:
            M[b-1] = 1
            M[b] = 0
            b -= 1
            turn *= -1
        elif M[b-1] == 1 and M[b+1] == 0:
            M[b+1] = 1
            M[b] = 0
            b += 1
            turn *= -1
        elif M[b-1] == 0 and M[b+1] == 0:
            M[b-1] = 1
            M[b] = 0
            b -= 1
            turn *= -1
        else:
            print("Alice")
            exit()