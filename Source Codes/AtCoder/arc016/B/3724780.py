N = int(input())

rythm = []
for i in range(N):
    S = list(input())
    rythm.append(S)

cnt = 0
renda = False
for column in range(9):
    renda = False
    for row in range(N):
        if renda == True:
            if rythm[row][column] == "o":
                continue
            else:
                renda = False
        
        if rythm[row][column] == "x":
            cnt += 1
        elif rythm[row][column] == "o":
            cnt += 1
            renda = True
        else:
            pass

print(cnt)