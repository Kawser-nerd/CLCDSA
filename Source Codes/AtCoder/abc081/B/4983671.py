num = int(input())
board = list(map(int, input().split()))
evener = 0
ope = True

while True:
    for i in range(num):
        if board[i]%2 == 0:
            board[i] = board[i]/2
        else:
            ope = False
            break
    if ope == True:
        evener+=1
    else:
        break

print(evener)